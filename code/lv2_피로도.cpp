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
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int solution(int k, vector<vector<int>> dungeons) {

    vector<int> v(dungeons.size());
    for (int i=0; i<v.size(); i++)
        v[i] = i;

    int mx = 0;
    do {
        int cnt = 0;
        int score = k;
        for (int i=0; i<v.size(); i++) {
            if (score < dungeons[v[i]][0]) break;
            cnt++;
            score -= dungeons[v[i]][1];
        }
        mx = max(mx, cnt);
    } while (next_permutation(v.begin(), v.end()));

    return mx;
}