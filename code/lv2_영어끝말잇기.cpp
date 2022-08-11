#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
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

vector<int> solution(int n, vector<string> words) {

    unordered_set<string> st;

    for (int i=0; i<words.size(); i++) {
        int p = i%n+1;
        int o = i/n+1;    
        if (words[i].size() == 1) return {p, 0}; //1글자일 때
        if (i != 0 && words[i-1].back() != words[i][0]) return {p, o}; //전 단어의 끝글자로 시작하지 않을 때
        if (st.find(words[i]) != st.end()) return {p, o}; //중복된 단어일 때
        st.insert(words[i]);
    }
    return {0, 0};
}