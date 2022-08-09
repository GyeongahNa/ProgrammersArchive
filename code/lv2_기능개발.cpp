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

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    queue<int> q;
    for (int i=0; i<progresses.size(); i++) //배포까지 남은 날짜 계산
        q.push((100-progresses[i]+speeds[i]-1)/speeds[i]);

    vector<int> ans;
    while (!q.empty()) { //한번 배포할 때
        int cnt = 0; //배포 개수 카운트
        int fr = q.front();
        while (!q.empty() && fr >= q.front()) {
            cnt++;
            q.pop();
        }
        ans.push_back(cnt);
    }
    return ans;
}