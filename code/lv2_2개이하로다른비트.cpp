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

vector<long long> solution(vector<long long> numbers) {
    
    vector<long long> v;
    
    for (long long x : numbers) {
        for (int i=0; i<=50; i++) {
            int d = ((x&(1LL<<i)) > 0);
            if (d == 1) continue;
            x = x|(1LL<<i);
            if (i > 0) x = x&(~(1LL<<(i-1)));
            break;
        }
        v.push_back(x);
    }
    return v;
}