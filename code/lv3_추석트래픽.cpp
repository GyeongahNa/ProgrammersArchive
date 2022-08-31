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

int y, m, d, hh, mm, ss, sss, t1, t2;
vector<int> vst, ven;

void parse(const vector<string>& lines) {
    
    for (auto x : lines) {

        sscanf(x.c_str(), "%d-%d-%d %d:%d:%d.%d %d.%ds", &y, &m, &d, &hh, &mm, &ss, &sss, &t1, &t2);
        int en = (hh*3600+mm*60+ss)*1000+sss;
        int T1 = (t1*1000-t1);
        int T2 = (t2 > 0 ? t2-1 : 0);
        int st = en-T1-T2;
        vst.push_back(st);
        ven.push_back(en);
    }
    
    sort(vst.begin(), vst.end());
    sort(ven.begin(), ven.end());
}

int solution(vector<string> lines) {
    
    parse(lines);
    
    int st = 0, en = 1000, cnt = 0, mx = 0;
    int stidx = 0, enidx = 0;
    int stn = vst.size(), enn = ven.size();
    
    while (stidx < stn || enidx < enn) {
        
        while (enidx < enn && ven[enidx] < st) {
            cnt--;
            enidx++;
        }
        while (stidx < stn && vst[stidx] <= en) {
            cnt++;
            stidx++;
        }
        
        mx = max(cnt, mx);
        st++, en++;
    }
    
    return mx;
}