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

#define X first
#define Y second

int solution(int n, vector<int> stations, int w) {

    vector<ii> v;

    for (auto x : stations) {
        int st = max(0, x-w);
        int en = min(n, x+w);
        int sz = (int)v.size();
        if (!sz || st > v[sz-1].Y+1) v.push_back({st, en});
        else v[sz-1].Y = max(v[sz-1].Y, en); //(st,en)가 가장 마지막 영역과 겹치면 끝 부분만 수정
    }

    int p = 1, cnt = 0;
    for (auto [st, en] : v) {
        cnt += (st-p+2*w)/(2*w+1); //(st-p)를 (2*w+1)로 나눈 후 올림한 값
        p = en+1;
    }

    if (p >= n+1) return cnt;
    return cnt += (n+1-p+2*w)/(2*w+1);
}