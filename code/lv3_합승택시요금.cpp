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
#include <cctype>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using l = long long;
using ll = pair<l, l>;

#define X first
#define Y second

vector<vector<l>> dist(205, vector<l>(205, INT_MAX));

void Floyd(int n, const vector<vector<int>>& fares) {

    for (int i=1; i<=n; i++) dist[i][i] = 0;

    for (auto v : fares) {
        l c = v[0];
        l d = v[1];
        l f = v[2];
        dist[c][d] = min(dist[c][d], f);
        dist[d][c] = min(dist[d][c], f);
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    Floyd(n, fares);

    l mn = INT_MAX;
    for (int i=1; i<=n; i++) 
        mn = min(mn, dist[s][i]+dist[i][a]+dist[i][b]);
    return mn;
}