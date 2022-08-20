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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    vector<int> v;
    vector<vector<int>> board(rows+1, vector<int>(columns+1, 0));
    
    for (int i=1; i<=rows; i++) {
        for (int j=1; j<=columns; j++)
            board[i][j] = ((i-1)*columns+j);
    }
    
    for (auto q : queries) {
        int x1 = q[0], y1 = q[1];
        int x2 = q[2], y2 = q[3];
        int h = x2-x1+1, w = y2-y1+1;
        int cx = x1, cy = y1;
        int tmp = board[x1][y1];
        int mn = tmp;

        for (int dir = 0; dir<4; dir++) {
            int len = 0;
            if (dir%2 == 0) len = h;
            else len = w;
            for (int i=0; i<len-1; i++) {
                int nx = cx+dx[dir];
                int ny = cy+dy[dir];
                board[cx][cy] = board[nx][ny];
                mn = min(board[cx][cy], mn);
                cx = nx;
                cy = ny;
            }
        }
        board[x1][y1+1] = tmp; 
        v.push_back(mn);
    }
    
    return v;
}