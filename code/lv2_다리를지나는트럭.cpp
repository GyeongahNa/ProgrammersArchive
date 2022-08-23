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



int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int bn = bridge_length;
    int tn = truck_weights.size();
    
    queue<int> q;
    int t = 0, sum = 0, idx = 0;
    
    while (idx < tn) {
        
        if (q.size() == bn) {
            sum -= q.front();
            q.pop();
        }
        
        int tmp = truck_weights[idx];
        if (sum+tmp <= weight) {
            q.push(tmp);
            sum += tmp;
            idx++;
        }
        else q.push(0);
        t++;
    }
    return t+bn;
}