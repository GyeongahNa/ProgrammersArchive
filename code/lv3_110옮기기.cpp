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

vector<string> solution(vector<string> s) {
    
    vector<string> ans;
    
    for (auto x : s) {
        
        int cnt = 0;
        stack<char> st;
        
        //"110"을 모두 뺀 문자열(left) 구하기
        for (auto c : x) {
            if ((int)st.size() < 2) {
                st.push(c);
                continue;
            }
            
            char t1 = st.top();
            st.pop();
            char t2 = st.top();
            st.pop();
            
            if (t1 == '1' && t2 == '1' && c == '0') {
                cnt++;
                continue;
            }
            
            st.push(t2);
            st.push(t1);
            st.push(c);
        }
        
        string left = "";
        while (!st.empty()) {
            left = st.top() + left;
            st.pop();
        }
        
        //뺀 만큼 붙여넣어야 하는 "110"
        string sub = "";
        for (int i=0; i<cnt; i++) sub += "110";
        
        //left의 오른쪽 끝에서 부터 '1'의 연속이 끝나는 지점에 연속된 "110"(sub) 붙이기
        int i = (int)left.size()-1;
        while (left[i] == '1') i--;
        
        string r = left.substr(0, i+1) + sub + left.substr(i+1);
        ans.push_back(r);
    }
    
    return ans;
}