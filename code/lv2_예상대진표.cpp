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

int solution(int n, int a, int b) {

    int round = 1;
    while (n != 1) {
        if ((a-1)/2 == (b-1)/2) return round;
        a = (a+1)/2;
        b = (b+1)/2;
        n /= 2;
        round++;
    }
    return round;
}