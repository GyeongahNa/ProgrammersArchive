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

string tolowerstr(string s) {

    string ret = "";
    for (auto x : s) 
        ret += tolower(x);
    return ret;
}

int solution(int cacheSize, vector<string> cities) {

    map<string, int> m;

    int t = 1, sum = 0;
    for (auto x : cities) {       
        x = tolowerstr(x);
        if (m.find(x) != m.end()) { //cache hit
            sum += 1;
            m[x] = t;
        }
        else { //cache miss
            sum += 5;
            if (cacheSize && m.size() >= cacheSize) {
                int mn = t+1;
                auto mit = m.begin();
                for (auto it=m.begin(); it!=m.end(); it++) {
                    if (mn <= it->Y) continue;
                    mn = it->Y;
                    mit = it;
                }
                m.erase(mit);
            }
            if (cacheSize) m[x] = t;
        }
        t++;
    }
    return sum;
}