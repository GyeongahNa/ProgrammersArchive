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

int mx;
vector<vector<int>> child(20, vector<int>(0));

void setGraph(const vector<int>& info, const vector<vector<int>>& edges) {

    for (auto v : edges) {
        int p = v[0];
        int c = v[1];
        child[p].push_back(c);
    }
}

void func(const vector<int>& info,int cur, int nlamb, int nwolf, vector<int> vnext) {

    if (nlamb <= nwolf) return;
    mx = max(nlamb, mx);

    for (auto next : vnext) {

        vector<int> tmp = vnext;
        tmp.erase(find(tmp.begin(), tmp.end(), next));
        for (auto x : child[next]) tmp.push_back(x);

        if (info[next]) func(info, next, nlamb, nwolf+1, tmp);
        else func(info, next, nlamb+1, nwolf, tmp); 
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    setGraph(info, edges);

    vector<int> vnext;
    for (auto x : child[0])
        vnext.push_back(x);

    func(info, 0, 1, 0, vnext);
    return mx;
}