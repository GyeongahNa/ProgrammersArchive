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

string solution(string number, int k) {

    stack<char> st;
    int cnt = 0;
    for (auto x : number) {
        while (!st.empty() && cnt < k && st.top() < x) {
            st.pop();
            cnt++;
        }
        st.push(x);
    }

    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    return ans.substr(0, number.size()-k);
}