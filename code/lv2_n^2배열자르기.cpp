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

vector<int> solution(int n, long long left, long long right) {

    vector<int> v;
    for (long long i=left; i<=right; i++)
        v.push_back(max(i/n, i%n)+1);
    return v;
}