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
bool dp[2505][2505];

int solution(string s) {

    int n = s.size();
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<n; j++) {
            if (i == j) dp[i][j] = true;
            else if (i+1 == j) {
                if (s[i] == s[j]) dp[i][j] = true;
            }
            else {
                if (dp[i+1][j-1] && s[i] == s[j]) dp[i][j] = true;
            }
            if (dp[i][j]) mx = max(mx, j-i+1);
        }
    }

    return mx;
}