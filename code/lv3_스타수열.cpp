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
vector<int> cnt(500005, 0);

int solution(std::vector<int> a) {

    n = (int)a.size();
    for (int i=0; i<n; i++) cnt[a[i]]++;

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (!cnt[i]) continue;
        if (cnt[i] <= ans) continue;

        int res = 0;
        for (int j=0; j<n-1; j++) {
            if (a[j] == i && a[j+1] != i) {
                res++;
                j++;
            }
            else if (a[j] != i && a[j+1] == i) {
                res++;
                j++;
            }
        }
        ans = max(res, ans);
    }

    return ans*2;
}