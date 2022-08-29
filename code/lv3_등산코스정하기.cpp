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

vector<vector<ii>> graph(50005, vector<ii>(0));
vector<int> intencity(50005, INT_MAX);
priority_queue<ii, vector<ii>, greater<ii>> pq;


bool check(int a, int b, const vector<int>& gates, const vector<int>& summits) {
    
    if (find(summits.begin(), summits.end(), b) != summits.end()) return false;
    if (find(gates.begin(), gates.end(), a) != gates.end()) return false;
    return true;
}

void setGraph(const vector<vector<int>> paths, const vector<int>& gates, const vector<int>& summits) {
    
    for (auto v : paths) {
        int i = v[0];
        int j = v[1];
        int w = v[2];
        if (check(i, j, gates, summits)) graph[j].push_back({i, w});
        if (check(j, i, gates, summits)) graph[i].push_back({j, w});
    }
}

void Dijkstra(const vector<int>& gates) {
    
    for (auto x : gates) {
        intencity[x] = 0;
        pq.push({0, x});
    }
    
    while (!pq.empty()) {
        
        ii cur = pq.top(); //(intencity, 노드)
        pq.pop();
        
        if (intencity[cur.Y] != cur.X) continue;
        for (auto [next, w] : graph[cur.Y]) {
            if (max(intencity[cur.Y], w) < intencity[next]) {
                intencity[next] = max(intencity[cur.Y], w);
                pq.push({intencity[next], next});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    setGraph(paths, gates, summits);
    Dijkstra(gates);
    
    vector<ii> v;
    for (auto x : summits) v.push_back({intencity[x], x});
    sort(v.begin(), v.end());
    
    return {v[0].Y, v[0].X};
}