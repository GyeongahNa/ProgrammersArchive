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

int board[105][105];
int memo[105][105];

int dfs(int x, int y, int n, int m) {

    if (x == n && y == m) return 1;
    if (memo[x][y]) return memo[x][y];

    long long re = 0;
    if (y+1 <= m && !board[x][y+1]) re += dfs(x, y+1, n, m);
    if (x+1 <= n && !board[x+1][y]) re += dfs(x+1, y, n, m);
    memo[x][y] = re%1000000007;
    return memo[x][y];
}

int solution(int m, int n, vector<vector<int>> puddles) {

    for (auto v : puddles) 
        board[v[1]][v[0]] = 1;
   return dfs(1, 1, n, m);
}