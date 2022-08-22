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

int solution(string name) {

    int ans = 0;
    for (auto x : name) //상하이동
        ans += min(x-'A', 'Z'-x+1);

    //좌우이동
    int n = name.size();
    int mn = n-1;
    for (int i=0; i<name.size(); i++) {
        int nexti = i+1;
        while (nexti < n && name[nexti] == 'A') nexti++;
        mn = min({mn, 2*i+(n-nexti), 2*(n-nexti)+i});
    }
    ans += mn;
    return ans;
}