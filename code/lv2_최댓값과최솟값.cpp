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

vector<string> split(string s) {

    vector<string> v;

    int st = 0;
    s += ' ';
    for (int i=0; i<s.size(); i++) {
        if (s[i] != ' ') continue;
        v.push_back(s.substr(st, i-st));
        st = i+1;
    }
    return v;
}

string solution(string s) {

    vector<string> v = split(s);

    int mn = stoi(v[0]);
    int mx = stoi(v[0]);
    for (int i=1; i<v.size(); i++) {
        int n = stoi(v[i]);
        mn = min(mn, n);
        mx = max(mx, n);
    }

    return to_string(mn)+" "+to_string(mx);
}