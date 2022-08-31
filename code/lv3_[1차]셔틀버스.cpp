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
#include <cctype>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string solution(int n, int t, int m, vector<string> timetable) {
    
    //timetable 시간을 정수로 변환
    vector<int> vperson;
    for (auto s : timetable) {
        int a, b;
        sscanf(s.c_str(), "%d:%d", &a, &b);
        vperson.push_back(a*60+b);
    }
    sort(vperson.begin(), vperson.end());

    //1번 차 부터 n번 차까지 크루 태우기
    int i = 0, sz = vperson.size(), ans = 0;
    for (int ncar=1; ncar<=n; ncar++) {
        int cnt = 0;
        int arrivet = 9*60+(ncar-1)*t; //셔틀 도착 시간
        while (i < sz && vperson[i] <= arrivet && cnt < m) { // 셔틀 도착 내에 온 사람 태우기
            cnt++;
            i++;
        }
        if (ncar == n) { //마지막 차
            if (cnt < m) ans = arrivet; //정원이 다 차지 않았다면 셔틀이 오는 시간에 나가야 함
            else ans = vperson[i-1]-1; //정원이 다 찼다면 마지막 사람 이전 시간에 나가야 함
        }
    }
    
    char tmp[50];
    int l = sprintf(tmp, "%02d:%02d", ans/60, ans%60);
    return string(tmp, l);
}