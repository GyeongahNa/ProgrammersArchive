
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
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