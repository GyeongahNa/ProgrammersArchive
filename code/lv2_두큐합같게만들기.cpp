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

int solution(vector<int> queue1, vector<int> queue2) {
    
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    int cnt = 0;
    
    for (auto x : queue1) {
        q1.push(x);
        sum1 += x;
    }
    
    for (auto x : queue2) {
        q2.push(x);
        sum2 += x;
    }
    
    while (true) {
        if (cnt > queue1.size()*3) break;
        if (sum1 == sum2) return cnt;
        else if (sum1 > sum2) {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
            cnt++;
        }
        else {
            sum1 += q2.front();
            sum2 -= q2.front();
            q1.push(q2.front());
            q2.pop();
            cnt++;
        }
    }
    return -1;
}