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

void bfs(int st, vector<bool>& visited, const vector<vector<int>> computers) {

    queue<int> q;
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<computers[cur].size(); i++) {
            if (!computers[cur][i]) continue;
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    vector<bool> visited(n, false);

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (visited[i]) continue;
        cnt++;
        bfs(i, visited, computers);
    }
    return cnt;
}