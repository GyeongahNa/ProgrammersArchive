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
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

bool cmp(string a, string b) {
    
    if (a+b > b+a) return true;
    return false;
}

string solution(vector<int> numbers) {
    
    vector<string> v;
    for (auto x : numbers) v.push_back(to_string(x));
    sort(v.begin(), v.end(), cmp);
    
    string s = "";
    for (auto x : v) s += x;
    
    if (s[0] == '0') return "0";
    return s;
}