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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps) {

    int n = maps.size();
    int m = maps[0].size();

    queue<ii> q;
    q.push({0, 0});

    int dist[100][100];
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) dist[i][j] = -1;
    }
    dist[0][0] = 0;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1 || !maps[nx][ny]) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }

    if (dist[n-1][m-1] == -1) return -1;
    return dist[n-1][m-1]+1;
}