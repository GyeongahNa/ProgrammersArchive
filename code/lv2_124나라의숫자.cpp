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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string solution(int n) {
    
    string s = "";
    while (n) {
        int d = n%3;
        n /= 3;
        if (d == 1) s += "1";
        else if (d == 2) s += "2";
        else { // d == 0
            s += "4";
            n--;   
        }
    }
    reverse(s.begin(), s.end());
    return s;
}