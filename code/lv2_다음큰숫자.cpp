#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

int cntOne(int n) {

    int cnt = 0;
    while (n) {
        if (n%2) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {

    int cnt = cntOne(n);

    for (int i=n+1; ; i++) {
        if (cntOne(i) == cnt) return i;
    }
    return -1;
}