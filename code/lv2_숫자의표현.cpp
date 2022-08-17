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

    int cnt = 1;
    for (int i=2; i<=n; i++) {
        int val = n-i*(i-1)/2;
        if (val%i == 0 && val/i > 0) cnt++;
    }
    return cnt;
}