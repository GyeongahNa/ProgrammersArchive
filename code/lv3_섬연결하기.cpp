#include <cstdio>
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

vector<iii> edge;
vector<int> nrank(100, 1);
vector<int> parent(100, 0);


void initialize(int n) {

    for (int i=0; i<n; i++) parent[i] = i;
}

int find(int u) {

    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u == v) return ;
    if (nrank[u] > nrank[v]) swap(u, v);
    else if (nrank[u] == nrank[v]) nrank[v]++;
    parent[u] = v;
}

void setGraph(const vector<vector<int>>& costs) {

    for (auto v : costs)
        edge.push_back({v[2], v[0], v[1]});
    sort(edge.begin(), edge.end());
}

int solution(int n, vector<vector<int>> costs) {

    setGraph(costs);
    initialize(n);

    int ans = 0;
    for (auto [w, u, v] : edge) {
        if (find(u) == find(v)) continue;
        merge(u, v);
        ans += w;
    }
    return ans;
}