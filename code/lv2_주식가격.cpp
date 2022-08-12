#include <cstdio>
#include <cstring>
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
using iii = tuple<int, int>;

#define X first
#define Y second

vector<int> solution(vector<int> prices) {
    
    stack<ii> st;
    vector<int> ans(prices.size(), 0);
    
    for (int i=0; i<prices.size(); i++) {   
        while (!st.empty() &&  st.top().Y > prices[i]) { //prices[i]를 떨어지는 수로 갖는 인덱스를 모두 찾기
            ans[st.top().X] = i-st.top().X;
            st.pop();
        }
        st.push({i, prices[i]});
    }
    
    while (!st.empty()) { //떨어지는 수가 없을 때 가장 끝 인덱스까지의 거리 구하기
        ans[st.top().X] = prices.size()-1-st.top().X;
        st.pop();
    }
    return ans;
}