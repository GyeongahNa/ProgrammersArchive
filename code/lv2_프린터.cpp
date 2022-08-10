#include <cstdio>
#include <cstring>
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

#define X first
#define Y second

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int solution(vector<int> priorities, int location) {

    queue<ii> q;
    for (int i=0; i<priorities.size(); i++) 
        q.push({i, priorities[i]});
    sort(priorities.begin(), priorities.end(), greater<>());

    int cnt = 0;
    int idx = 0;
    while (true) { //문서 하나 프린트
        cnt++;
        //우선순위에 맞는 문서가 나올 떄까지 뒤로 보내기
        while (!q.empty() && q.front().Y != priorities[idx]) { 
            q.push(q.front());
            q.pop();
        }
        if (q.front().X == location) break; //출력될 문서의 초기 위치가 요청된 문서일 때 중단
        q.pop(); //출력
        idx++; 
    }
    return cnt;
}