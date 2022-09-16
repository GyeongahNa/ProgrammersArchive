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

int solution(int n, vector<int> weak, vector<int> dist) {
    
    sort(dist.begin(), dist.end(), greater<>());

    for (int i=1; i<=(int)dist.size(); i++) {
        
        vector<int> order;
        for (int j=0; j<i; j++) order.push_back(dist[j]);
        sort(order.begin(), order.end());
        
        do {
            vector<int> W = weak;
            for (int k=0; k<(int)W.size(); k++) {
                
                int idx = 0;
                for (auto d : order) {
                    int st = idx;
                    for (; idx < (int)W.size() && W[idx] <= W[st]+d; idx++) {}
                }
                if (idx >= (int)W.size()) return i;

                W.push_back(W[0]+n);
                W.erase(W.begin());
            }
            
        }
        while (next_permutation(order.begin(), order.end()));
    }
    
    return -1;
}