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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using is = pair<int, string>;

#define X first
#define Y second

bool cmp(ii a, ii b) {
    if (a.X > b.X) return true;
    if (a.X < b.X) return false;
    if (a.Y < b.Y) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    map<string, vector<ii>> minfo;
    map<string, int> nplay;

    int sz = genres.size();
    for (int i=0; i<sz; i++) {
        nplay[genres[i]] += plays[i];
        minfo[genres[i]].push_back({plays[i], i});
    }

    for (auto it=minfo.begin(); it!=minfo.end(); it++) {
        sort((*it).Y.begin(), (*it).Y.end(), cmp);
    }

    vector<is> vnplay;
    for (auto [g, n] : nplay) vnplay.push_back({n, g});
    sort(vnplay.begin(), vnplay.end(), greater<>());

    vector<int> vans;
    for (auto [n, g] : vnplay) {
        for (int i=0; i<2 && i<minfo[g].size(); i++)
            vans.push_back(minfo[g][i].Y);
    }
    return vans;
}