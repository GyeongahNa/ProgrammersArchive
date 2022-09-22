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
using ll = long long;

#define X first
#define Y second

int sz, nwork, mx;

bool check(ll t, const vector<int>& cores) {

    ll cnt = sz;
    for (int i=0; i<sz; i++)
        cnt += t/cores[i];
    return cnt >= nwork;
}

int binarySearch(const vector<int>& cores) {

    int first = 0;
    int last = mx*(nwork/sz);
    int ret = last;

    while (first <= last) {
        ll mid = (first+last)/2;
        if (check(mid, cores)) {
            ret = mid;
            last = mid-1;
        }
        else first = mid+1;
    }

    return ret;
}

int solution(int n, vector<int> cores) {

    nwork = n;
    sz = cores.size();
    for (int i=0; i<sz; i++) mx = max(cores[i], mx);

    //t: 작업을 n개 이상 수행하기 위한 최소 시각
    int t = binarySearch(cores);
    if (t == 0) return n;

    //cnt: t-1시간까지의 작업량
    ll cnt = sz;
    for (int i=0; i<sz; i++) 
        cnt += (t-1)/cores[i];

    //시각 t에 작업이 추가될 때 n번째 작업이 추가되는 코어 번호 리턴
    for (int i=0; i<sz; i++) {
        if (t%cores[i] != 0) continue;
        if (++cnt == n) return i+1;
    }

    return -1;
}