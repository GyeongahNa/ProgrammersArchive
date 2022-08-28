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

vector<string> ans;
vector<bool> visited(100000005, false);
bool flag;

void dfs(string x, int cnt, const vector<vector<string>>& tickets) {

    if (cnt >= tickets.size()) flag = true;
    ans.push_back(x);

    for (int i=0; i<tickets.size(); i++) {
        if (visited[i] || tickets[i][0] != x) continue;
        visited[i] = true;
        dfs(tickets[i][1], ++cnt, tickets);

        //중간에 끊기는 경우 방지
        if (!flag) {
            visited[i] = false;
            ans.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    dfs("ICN", 0, tickets);
    return ans;
}