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

int solution(string s) {
    stack<char> st;
    for (auto c : s) {
        if (!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    return (int)st.empty();
}