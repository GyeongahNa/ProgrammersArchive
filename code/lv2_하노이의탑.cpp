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
#include <unordered_map>
#include <unordered_set>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

vector<vector<int>> func(int n, int f, int t) {

    if (n == 1) return {{f, t}};
    vector<vector<int>> v1 = func(n-1, f, 6-f-t);
    v1.push_back({f, t});
    vector<vector<int>> v2 = func(n-1, 6-f-t, t);
    for (auto x : v2) v1.push_back(x);
    return v1;
}

vector<vector<int>> solution(int n) {
    return func(n, 1, 3);
}