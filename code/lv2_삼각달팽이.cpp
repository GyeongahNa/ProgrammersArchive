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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ddi = tuple<double, double, int>;

#define X first
#define Y second

double dx[3] = {1, 0, -1};
double dy[3] = {-0.5, 1, -0.5};

vector<int> solution(int n) {
    
    vector<ddi> v;
    double x = 0, y = 0;
    int dir = 0, cnt = 1;
    
    for (int i=n; i>=1; i--) {
        for (int j=0; j<i; j++) {
            v.push_back({x, y, cnt++});
            if (j == i-1) dir = (dir+1)%3;
            x += dx[dir];
            y += dy[dir];
        }
    }
    
    sort(v.begin(), v.end());
    
    vector<int> ans;
    for (auto [x, y, num] : v) ans.push_back(num);
    return ans;
}