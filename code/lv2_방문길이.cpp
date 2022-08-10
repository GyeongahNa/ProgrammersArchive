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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define HALF 5

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[15][15][15][15];

bool OOB(int x, int y) {
    return x < 0 || x > 10 || y < 0 || y > 10;
}

int solution(string dirs) {

    int cnt = 0;
    int bfx = HALF;
    int bfy = HALF;

    for (auto d : dirs) {
        int curx = bfx;
        int cury = bfy;
        for (int i=0; i<4; i++) {
            if ("UDLR"[i] != d) continue;
            curx += dx[i];
            cury += dy[i];
        }

        if (OOB(curx, cury)) continue; //새로운 좌표가 범위를 벗어나는 경우 무시
        if (!visited[bfx][bfy][curx][cury]) { //이전에 방문한적 없는 길이라면 cnt 증가
            cnt++;
            visited[bfx][bfy][curx][cury] = true;
            visited[curx][cury][bfx][bfy] = true;
        }

        bfx = curx; //최신 좌표 업데이트
        bfy = cury;
    }

    return cnt;
}