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
using namespace std;

#define X first
#define Y second

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto e : scoville)
        pq.push(e);

    int cnt = 0;
    while (pq.size() >= 2) {
        if (pq.top() >= K) return cnt; //가장 작은 값이 K이상이면 모든 값이 K이상
        int n1 = pq.top(); //가장 작은 두개를 뽑아 새로운 스코빌 생성
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        pq.push(n1+n2*2); 
        cnt++;
    }

    if (pq.top() >= K) return cnt;
    return -1;
}