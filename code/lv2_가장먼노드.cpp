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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

void setGraph(vector<vector<int>>& graph, const vector<vector<int>> edge) {
    
    for (auto v : edge) {
        int a = v[0];
        int b = v[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void bfs(vector<int>& dist, const vector<vector<int>> graph) {
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        
        int cur = q.front();
        q.pop();

        for (auto x : graph[cur]) {
            if (dist[x] != -1) continue;
            dist[x] = dist[cur]+1;
            q.push(x);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    
    vector<vector<int>> graph(n+1, vector<int>(0));
    setGraph(graph, edge);
    
    vector<int> dist(n+1, -1);
    bfs(dist, graph);
    
    int cnt = 0;
    int mx = *max_element(dist.begin(), dist.end());
    for(auto x : dist) 
        if (x == mx) cnt++;
    return cnt;
}