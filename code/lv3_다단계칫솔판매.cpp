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

map<string, int> benefit;
map<string, vector<string>> graph;

void setGraph(const vector<string>& enroll, const vector<string>& referral) {
    
    for (int i=0; i<enroll.size(); i++) {
        if (referral[i] == "-") continue;
        graph[enroll[i]].push_back(referral[i]);
    }
}

void share(string x, int n) {
    
    int minus = n/10;
    int add = n-minus;
    benefit[x] += add;
    
    if (graph[x].size() == 0 || !minus) return;
    share(graph[x][0], minus);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    setGraph(enroll, referral);
    
    for (int i=0; i<seller.size(); i++)
        share(seller[i], amount[i]*100);
    
    vector<int> ans;
    for (auto x : enroll) 
        ans.push_back(benefit[x]);
    return ans;
}