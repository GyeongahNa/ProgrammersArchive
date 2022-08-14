#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

string solution(string s) {

    string ans = "";
    
    int i = 0;
    while (i < s.size()) { 
        ans += toupper(s[i++]); 
        while (i < s.size() && s[i] != ' ') ans += tolower(s[i++]); 
        while (i < s.size() && s[i] == ' ') ans += s[i++]; 
    }
    return ans;
}