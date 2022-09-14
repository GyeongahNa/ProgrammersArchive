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

int MOD = 20170805;
int memo[2][505][505];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool OOB(int x, int y, int m, int n) {
    return 0 > x || x >= m || 0 > y || y >= n;
}

int dfs(int d, int x, int y, int m, int n, const vector<vector<int>>& city_map) {
    
    if (x == m-1 && y == n-1) return 1;
    if (memo[d][x][y] != -1) return memo[d][x][y];
    
    int ret = 0;
    for (int k=0; k<2; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (OOB(nx, ny, m, n)) continue; 
        if (!city_map[x][y] || (city_map[x][y] == 2 && d == k)) {
            ret += dfs(k, nx, ny, m, n, city_map);
            ret %= MOD;
        }
    }
    
    return memo[d][x][y] = ret;
}

int solution(int m, int n, vector<vector<int>> city_map) {

    memset(memo, -1, sizeof(memo));
    return dfs(0, 0, 0, m, n, city_map);    
}