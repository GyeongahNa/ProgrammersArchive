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

int mn = 100;
vector<bool> visited(55, false);

bool check(string a, string b) {

    int cnt = 0;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    return (cnt == 1);
}

void func(string x, int cnt, string target, const vector<string>& words) {

    if (x == target) {
        mn = min(mn, cnt);
        return ;
    }

    for (int i=0; i<words.size(); i++) {
        if (visited[i] || !check(x, words[i])) continue;
        visited[i] = true;
        func(words[i], cnt+1, target, words);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {

    func(begin, 0, target, words);
    if (mn == 100) return 0;
    return mn;
}