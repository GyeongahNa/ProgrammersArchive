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
#include <unordered_map>
#include <unordered_set>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int solution(int n) {
    
    int f[100005];
    
    f[0] = 0; f[1] = 1;
    for (int i=2; i<=n; i++)
        f[i] = (f[i-2]+f[i-1])%1234567;
    
    return f[n];
}