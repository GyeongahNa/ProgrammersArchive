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

int m, n;

void rotate(vector<vector<int>>& key) {
    
    vector<vector<int>> tmp(m, vector<int>(m, 0));
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++)
            tmp[i][j] = key[m-1-j][i];
    }
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) 
            key[i][j] = tmp[i][j];
    }
}

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void checkKeyArea(vector<vector<int>>& tmp, const vector<vector<int>>& key, int stx, int sty) {
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            int nx = i+stx;
            int ny = j+sty;
            if (OOB(nx, ny)) continue;
            tmp[nx][ny] = key[i][j];
        }
    }
}

bool compare(const vector<vector<int>>& tmp, const vector<vector<int>> lock) {
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (tmp[i][j] == lock[i][j]) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    m = (int)key.size();
    n = (int)lock.size();
    
    for (int i=0; i<4; i++) {
        if (i != 0) rotate(key);
        
        for (int stx=-(m-1); stx<=(n-1+m-1); stx++) {
            for (int sty=-(m-1); sty<=(n-1+m-1); sty++) {
                vector<vector<int>> tmp(n, vector<int>(n, 0));
                checkKeyArea(tmp, key, stx, sty);
                if (compare(tmp, lock)) return true;

            }
        }
    }
    return false;
}