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
using l = long long;

bool check(l limits, l n, const vector<int>& times) {

    l t = 0;
    for (int i=0; i<times.size(); i++) 
        t += limits/(1LL*times[i]);
    return t >= n;
}

l binarySearch(l n, const vector<int>& times) {

    l first = 1;
    l last = (*min_element(times.begin(), times.end()))*n;
    l ret = last;

    while (first <= last) {
        l mid = (first+last)/2;
        if (check(mid, n, times)) {
            ret = mid;
            last = mid-1;
        }
        else first = mid+1;
    }
    return ret;
}

long long solution(int n, vector<int> times) {

    return binarySearch(n, times);
}