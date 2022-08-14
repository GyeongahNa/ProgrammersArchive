#include <cstdio>
#include <cstring>
#include <cstdio>
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

#define X first
#define Y second

int change(string& s) {

    int cnt = 0;
    for (auto x : s)
        if (x == '1') cnt++; //1 카운트
    int ret = s.size()-cnt; //제거한 0의 개수 리턴

    string tmp = "";
    while (cnt) {
        tmp = to_string(cnt%2) + tmp;
        cnt /= 2;
    }
    s = tmp;

    return ret;
}

vector<int> solution(string s) {

    int t = 0;
    int cnt = 0;
    while (s != "1") {
        cnt += change(s); //이진변환
        t++;
    }
    return {t, cnt};
}