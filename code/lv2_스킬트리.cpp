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

bool check(string s, string skill) {
    
    vector<int> v;
    
    for (auto x : s) {
        int i = skill.find(x);
        if (i == string::npos) continue;
        v.push_back(i);
    }
    
    for (int i=0; i<v.size(); i++) {
        if (v[i] != i) return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    
    int cnt = 0;
    for (auto s : skill_trees) {
        if (check(s, skill)) cnt++;
    }
    return cnt;
}