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

bool solution(string s) {

    stack<char> st;

    for (auto x : s) {
        if (x == '(') st.push(x);
        else if (st.empty()) return false;
        else st.pop();
    }
    return st.empty();
}