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

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, vector<string>> mp;
    
    for (auto v : clothes)
        mp[v[1]].push_back(v[0]);
    
    int ret = 1;
    for (auto [k, v] : mp)
        ret *= (v.size()+1);
    return ret-1;
}