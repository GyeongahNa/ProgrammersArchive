#include <cstdio>
#include <cstring>
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

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {

    sort(routes.begin(), routes.end(), cmp);

    int x = routes[0][1], cnt = 1;
    for (int i=1; i<routes.size(); i++) {
        if (routes[i][0] <= x) continue;
        x = routes[i][1];
        cnt++;
    }

    return cnt;
}