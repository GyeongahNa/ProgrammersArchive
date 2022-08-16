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
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end(), greater<>());
    
    int ans = 0;
    for (int i=1; i<=citations.size(); i++)
        if (citations[i-1] > i) ans++;
    return ans;
}