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

int gcd(int a, int b) {

    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int solution(vector<int> arr) {

    int ans = arr[0];
    for (int i=1; i<arr.size(); i++)
        ans = lcm(ans, arr[i]);
    return ans;
}
