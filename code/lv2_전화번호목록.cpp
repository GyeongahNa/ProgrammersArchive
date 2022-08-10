#include <cstdio>
#include <cstring>
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

bool cmp(string a, string b) {
    if (a.size() < b.size()) return true;
    return false;
}

bool solution(vector<string> phone_book) {

    unordered_set<string> st;
    sort(phone_book.begin(), phone_book.end(), cmp);

    for (auto s : phone_book) {
        string tmp = "";
        for (auto c : s) {
            tmp += c;
            if (st.find(tmp) != st.end()) return false;
        }
        st.insert(tmp);
    }
    return true;
}