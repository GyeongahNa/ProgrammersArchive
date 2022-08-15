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

vector<int> solution(int brown, int yellow) {
    
    int s = (brown+4)/2;
    int st = (s+1)/2;
    int en = s-3;
    for (int w=st; w<=en; w++) {
        int h = s-w;
        if ((w-2)*(h-2) == yellow) return {w, h};
    }
    return {-1, -1};
}