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

using namespace std;
using ii = pair<int, int>;
using iii =tuple<int, int, int>;

#define X first
#define Y second

int solution(vector<vector<int>> jobs) {
    
    priority_queue<ii, vector<ii>, greater<ii>> pq, tmp;
    
    for (auto v : jobs)
        pq.push({v[1], v[0]}); //{소요시간, 요청시간}
    
    int t = 0, sum = 0;
    while (!pq.empty()) {
        
        // 현재 시간 t 이전에 들어온 요청 중 가장 소요시간이 짧은 작업 선택
        int sz = pq.size();
        bool flag = false;
        while (sz--) {
            ii cur = pq.top();
            pq.pop();
            if (cur.Y > t) tmp.push(cur);
            else {
                sum += t-cur.Y+cur.X;
                t += cur.X;
                flag = true;
                break;
            }
        }
        
        while (!tmp.empty()) {
            pq.push(tmp.top());
            tmp.pop();
        }
        
        //t 이전에 요청된 작업이 없다면 t 증가
        if (!flag) t++;
    }
    
    return sum/(int)jobs.size();
}