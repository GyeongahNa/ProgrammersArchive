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
using ll = long long;

#define X first
#define Y second

ll cnt;
vector<ll> aa(300005);
vector<bool> check(300005, false);
vector<vector<int>> graph(300005, vector<int>(0));

void func(int cur) {

    check[cur] = true;
    for (int x : graph[cur]) {
        if (check[x]) continue;
        func(x);
        cnt += abs(aa[x]);
        aa[cur] += aa[x];
    }   
}

void setGraph(const vector<int>& a, const vector<vector<int>>& edges) {

    for (int i=0; i<(int)a.size(); i++)
        aa[i] = 1LL*a[i];

    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {

    ll sum = 0;
    for (ll x : a) sum += x;
    if (sum) return -1; 

    setGraph(a, edges);
    func(0);    
    return cnt;
}