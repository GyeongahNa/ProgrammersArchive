#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

string tmp;
set<string> sset;
vector<bool> visited(100, false);

bool check(string user, string banned) {
    
    if (user.size() != banned.size()) return false;
    for (int i=0; i<(int)user.size(); i++) {
        if (banned[i] == '*') continue;
        if (user[i] != banned[i]) return false;
    }
    return true;
}

void func(int k, const vector<string>& user_id, const vector<string>& banned_id) {
    
    if (k >= (int)banned_id.size()) {
        string s = tmp;
        sort(s.begin(), s.end());
        sset.insert(s);
        return ;
    }
    
    for (int i=0; i<(int)user_id.size(); i++) {
        if (visited[i]) continue;
        if (!check(user_id[i], banned_id[k])) continue;
        visited[i] = true;
        tmp += i+'0';
        func(k+1, user_id, banned_id);
        visited[i] = false;
        tmp.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    func(0, user_id, banned_id);    
    return sset.size();
}