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
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int solution(vector<int> A, vector<int> B) {

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    int ret = 0;
    for (int i=0; i<A.size(); i++)
        ret += A[i]*B[i];
    return ret;
}