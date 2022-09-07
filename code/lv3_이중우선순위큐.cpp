#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
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

vector<int> solution(vector<string> operations) {

    priority_queue<int, vector<int>, greater<int>> mnpq;
    priority_queue<int, vector<int>, less<int>> mxpq;

    int cnt = 0;
    for (auto cmd : operations) {
        char c;
        int x;
        sscanf(cmd.c_str(), "%c %d", &c, &x);

        if (!cnt) {
            while (!mnpq.empty()) mnpq.pop();
            while (!mxpq.empty()) mxpq.pop();
        }

        if (c == 'I') {
            mnpq.push(x);
            mxpq.push(x);
            cnt++;
        }
        else if (x == 1 && !mxpq.empty()) {
            mxpq.pop();
            cnt--;
        }
        else if (x == -1 && !mnpq.empty()) {
            mnpq.pop();
            cnt--;
        }   
    }

    if (!cnt) return {0, 0};
    return {mxpq.top(), mnpq.top()};
}