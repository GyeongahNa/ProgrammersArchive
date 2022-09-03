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

vector<int> solution(vector<string> gems) {

    set<string> sset;
    for (auto x : gems) sset.insert(x);

    map<string, int> m;

    int l = 0, r = 0;
    m[gems[0]]++;
    vector<iii> v;

    while (l <= r && r < gems.size()) {
        if (m.size() == sset.size()) { 
        //[l, r] 구간이 모든 보석을 포함하고 있을 때 l을 오른쪽으로 이동            
            v.push_back({r-l+1, l, r});
            m[gems[l]]--;
            if (m[gems[l]] == 0) 
                m.erase(gems[l]);
            l++;
        }
        else { 
            //[l, r] 구간이 모든 보석을 포함하고 있지 않을 때 r을 오른쪽으로 이동
            r++;
            if (r < gems.size()) m[gems[r]]++;
        }
    }

    sort(v.begin(), v.end());
    return {get<1>(v[0])+1, get<2>(v[0])+1};
}