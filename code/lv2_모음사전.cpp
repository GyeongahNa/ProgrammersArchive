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

int ans, cnt;
char arr[10];

void func(int k, const string& word) {

    string s = "";
    for (int i=0; i<k; i++)
        s += arr[i];

    if (s == word) ans = cnt;
    if (k >= 5) return;

    for (int i=0; i<5; i++) {
        arr[k] = "AEIOU"[i];
        cnt++;
        func(k+1, word);
    }
}

int solution(string word) {

    func(0, word);
    return ans;
}