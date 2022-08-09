#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

long long gcd(long long a, long long b) {
    
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long solution(int w,int h) {
    
    long long g = gcd(h, w);
    return 1LL*h*w-(h/g+w/g-1)*g;
}