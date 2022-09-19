#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

#define X first
#define Y second

ll mx;
int pt, at, ans;
int h1, m1, s1, h2, m2, s2;

vector<ii> vlog;
vector<int> rec(400000, 0);

int tosec(int h, int m, int s) {
    return h*3600+m*60+s;
}

string tostr(int sec) {

    char tmp[50];
    int l = sprintf(tmp, "%02d:%02d:%02d", sec/3600, sec%3600/60, sec%3600%60);
    return string(tmp, l);
}

void setConditions(const string& play_time, const string& adv_time, const vector<string>& logs) {

    sscanf(play_time.c_str(), "%d:%d:%d", &h1, &m1, &s1);
    pt = tosec(h1, m1, s1);

    sscanf(adv_time.c_str(), "%d:%d:%d", &h1, &m1, &s1);
    at = tosec(h1, m1, s1);

    for (auto x : logs) {
        sscanf(x.c_str(), "%d:%d:%d-%d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int st = tosec(h1, m1, s1);
        int en = tosec(h2, m2, s2);
        vlog.push_back({st, +1});
        vlog.push_back({en, -1});
    }
    sort(vlog.begin(), vlog.end());
}

//각 시간대를 포함할 때 누적되는 재생시간을 구해 rec[t]에 저장
void setRec() {

    int t = 0, idx = 0, cnt = 0;
    while (t <= pt) {
        int plus = 0, minus = 0;
        while (idx < (int)vlog.size() && vlog[idx].X == t) {
            if (vlog[idx].Y == +1) plus++;
            else minus++;
            idx++;
        }
        rec[t] = cnt;
        cnt += (plus-minus);
        t++;
    }
}

//슬라이딩 윈도우로 크기가 at인 구간의 최대 합 구하기
void findStart() {

    ll sum = 0;
    int st = 0, en = 1;

    //(0, at]까지의 합
    while (en <= at) sum += rec[en++];
    en--;
    mx = sum;

    //st와 en을 한칸씩 이동하여 합 갱신
    while (en < pt) {
        sum += rec[++en];
        sum -= rec[++st];
        if (sum > mx) { //합의 최댓값 저장
            mx = sum;
            ans = st;
        }
    }
}

string solution(string play_time, string adv_time, vector<string> logs) {

    setConditions(play_time, adv_time, logs);
    setRec();
    findStart();
    return tostr(ans);
}