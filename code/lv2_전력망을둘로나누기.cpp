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

void setGraph(vector<vector<int>>& graph, const vector<vector<int>>& wires, int idx) {
    
    for (int i=0; i<wires.size(); i++) {
        if (idx == i) continue;
        int u = wires[i][0];
        int v = wires[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int cntNodes(const vector<vector<int>>& graph, int start) {
    
    vector<bool> check(graph.size(), false);
    
    int cnt = 0;
    queue<int> q;
    q.push(start);
    check[start] = true;
    
    while (!q.empty()) {
        
        int cur = q.front();
        q.pop();
        cnt++;
        
        for (auto x : graph[cur]) {
            if (check[x]) continue;
            q.push(x);
            check[x] = true;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    
    int mn = n;
    for (int i=0; i<wires.size(); i++) {
        vector<vector<int>> graph(n+1, vector<int>(0));
        setGraph(graph, wires, i);
        int cnt = cntNodes(graph, wires[i][0]);
        mn = min(mn, abs(cnt-(n-cnt)));
    }
    return mn;
}