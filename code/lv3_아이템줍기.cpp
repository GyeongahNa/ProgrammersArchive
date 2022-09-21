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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int chx, chy, ix, iy;
int board[110][110];
int dist[110][110];

void setDist() {
    
    for (int i=0; i<110; i++) {
        for (int j=0; j<110; j++)
            dist[i][j] = -1;
    }
}

void setBoard(const vector<vector<int>>& rectangle) {
    
    //직사각형 부분을 1로 채우기
    for (int i=0; i<(int)rectangle.size(); i++) {
        
        int x1 = rectangle[i][1]*2;
        int y1 = rectangle[i][0]*2;
        int x2 = rectangle[i][3]*2;
        int y2 = rectangle[i][2]*2;
        
        for (int j=x1; j<=x2; j++) {
            for (int k = y1; k<=y2; k++) {
                board[j][k] = 1;
            }
        } 
    }
    
    //직사각형 내부만 0으로 채우기
    //결국 board에는 직사각형 테두리만 남게 됨
    for (int i=0; i<(int)rectangle.size(); i++) {
        
        int x1 = rectangle[i][1]*2;
        int y1 = rectangle[i][0]*2;
        int x2 = rectangle[i][3]*2;
        int y2 = rectangle[i][2]*2;
        
        for (int j=x1+1; j<x2; j++) {
            for (int k = y1+1; k<y2; k++) {
                board[j][k] = 0;
            }
        } 
    }
}

bool OOB(int x,  int y) {
    return x < 0 || x >= 110 || y < 0 || y >= 110;
}

int bfs() {
    
    queue<ii> q;
    q.push({chx*2, chy*2});
    dist[chx*2][chy*2] = 0;
    
    while (!q.empty()) {
        
        ii cur = q.front();
        q.pop();
        
        if (cur.X == ix*2 && cur.Y == iy*2) return dist[cur.X][cur.Y]/2;
        
        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (OOB(nx, ny)) continue;
            if (!board[nx][ny] || dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    //x:세로좌표, y:가로좌표
    //모든 좌표를 2배씩 늘려 처리

    ix = itemY, iy = itemX;
    chx = characterY, chy = characterX;
    
    setDist();
    setBoard(rectangle);   
    return bfs();
}