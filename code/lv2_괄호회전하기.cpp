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

char getPair(char x) {

    if (x == ')') return '(';
    if (x == ']') return '[';
    return '{';
}

bool check(string s) {

    stack<char> st;

    for (auto x : s) {
        if (x == '(' || x == '[' || x == '{') st.push(x);
        else if (!st.empty() && st.top() == getPair(x)) st.pop();
        else return false;
    }
    return st.empty();
}

int solution(string s) {

    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        string tmp = s.substr(i)+s.substr(0, i); //회전한 문자열
        if (check(tmp)) cnt++;
    }
    return cnt;
}