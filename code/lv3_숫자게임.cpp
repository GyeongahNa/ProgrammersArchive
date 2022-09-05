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

#define X first
#define Y second

int solution(vector<int> A, vector<int> B) {

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int idx = 0, nwin = 0;
    for (int i=0; i<(int)A.size(); i++) {
        while (idx < (int)B.size() && A[i] >= B[idx]) idx++;
        if (idx < B.size()) {
            idx++;
            nwin++;
        }
    }
    return nwin;
}