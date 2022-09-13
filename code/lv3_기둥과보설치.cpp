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

bool pan[110][110];
bool pil[110][110];

bool OOB(int x, int y, int n) {
    return x < 0 || x > n || y < 0 || y > n;
}

bool pillar(int x, int y, int n) {

    if (x == 0) return true;
    if (!OOB(x, y-1, n) && pan[x][y-1] || pan[x][y]) return true;
    if (!OOB(x-1, y, n) && pil[x-1][y]) return true;
    return false;
}

bool panel(int x, int y, int n) {

    if (!OOB(x-1, y, n) && pil[x-1][y]) return true;
    if (!OOB(x-1, y+1, n) && pil[x-1][y+1]) return true;
    if (!OOB(x, y-1, n) && !OOB(x, y+1, n) && pan[x][y-1] && pan[x][y+1]) return true;
    return false;    
}

void add(int x, int y, int a, int n) {

    if (a == 0 && pillar(x, y, n)) pil[x][y] = true;
    if (a == 1 && panel(x, y, n)) pan[x][y] = true;
}

void del(int x, int y, int a, int n) {

    if (a == 0) pil[x][y] = false;
    else pan[x][y] = false;

    bool flag = true;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (pil[i][j] && !pillar(i, j, n)) flag = false;
            if (pan[i][j] && !panel(i, j, n)) flag = false;
        }
    }

    if (!flag) {
        if (a == 0) pil[x][y] = true;
        else pan[x][y] = true;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

    for (const auto& v : build_frame) {
        if (v[3] == 1) add(v[1], v[0], v[2], n);
        else del(v[1], v[0], v[2], n);
    }

    vector<vector<int>> ans;
    for (int i=0; i<=n; i++)  {
        for (int j=0; j<=n; j++) {
            if (pil[i][j]) ans.push_back({j, i, 0});
            if (pan[i][j]) ans.push_back({j, i, 1});
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}