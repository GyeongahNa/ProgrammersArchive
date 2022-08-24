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

void func(int k, int& cnt, vector<bool>& check1, vector<bool>& check2, vector<bool>& check3, int n) {

    if (k >= n) {
        cnt++;
        return ;
    }

    for (int i=0; i<n; i++) {
        if (check1[i]) continue;
        if (check2[k+i]) continue;
        if (check3[k-i+(n-1)]) continue;
        check1[i] = true;
        check2[k+i] = true;
        check3[k-i+(n-1)] = true;
        func(k+1, cnt, check1, check2, check3, n);
        check1[i] = false;
        check2[k+i] = false;
        check3[k-i+(n-1)] = false;
    }
}

int solution(int n) {

    vector<bool> check1(n, false);
    vector<bool> check2(2*n, false);
    vector<bool> check3(2*n, false);

    int cnt = 0;
    func(0, cnt, check1, check2, check3, n);
    return cnt;
}