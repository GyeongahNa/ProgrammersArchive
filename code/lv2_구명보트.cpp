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

int solution(vector<int> people, int limit) {

    sort(people.begin(), people.end());

    int l = 0, r = people.size()-1, cnt = 0;
    while (l < r) {
        if (people[l]+people[r] <= limit) l++;
        r--;
        cnt++;
    }

    if (l == r) cnt++;
    return cnt;
}