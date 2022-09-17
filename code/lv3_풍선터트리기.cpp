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

int n;
int lmn[1000005];
int rmn[1000005];

int solution(vector<int> a) {

    n = (int)a.size();

    lmn[0] = a[0];
    for (int i=1; i<n; i++)
        lmn[i] = min(lmn[i-1], a[i]);

    rmn[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--)
    rmn[i] = min(rmn[i+1], a[i]);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        if (i >= 1 && lmn[i-1] < a[i]) cnt++;
        if (i+1 < n && rmn[i+1] < a[i]) cnt++;
        if (cnt < 2) ans++;
    }

    return ans;
}
