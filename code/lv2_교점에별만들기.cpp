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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using l = long long;
using ll = pair<l, l>;

#define X first
#define Y second

vector<string> solution(vector<vector<int>> line) {
    
    int n = line.size();

    //2개 직선을 선택하여 가능한 모든 교점 구하기
    set<ll> st;
    l A, B, C, D, E, F;

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            A = line[i][0], B = line[i][1], E = line[i][2];
            C = line[j][0], D = line[j][1], F = line[j][2];
            if (A*D-B*C != 0) {
                if ((B*F-E*D)%(A*D-B*C) == 0 && (E*C-A*F)%(A*D-B*C) == 0)
                    st.insert({(E*C-A*F)/(A*D-B*C), (B*F-E*D)/(A*D-B*C)});
            }
        }
    }
    
    //교점을 좌표에 나타내기
    l mnx = LLONG_MAX, mny = LLONG_MAX;
    l mxx = LLONG_MIN, mxy = LLONG_MIN;
    
    for (auto [x, y] : st) {
        mnx = min(mnx, x);
        mxx = max(mxx, x);
        mny = min(mny, y);
        mxy = max(mxy, y);
    }

    vector<string> ans(mxx-mnx+1, string(mxy-mny+1, '.'));    
    for (auto [x, y] : st) ans[mxx-x][y-mny] = '*'; 
    return ans;
}