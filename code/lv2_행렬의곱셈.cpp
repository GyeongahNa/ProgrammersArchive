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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int r1 = arr1.size();
    int c1 = arr1[0].size();
    int r2 = arr2.size();
    int c2 = arr2[0].size();
    
    vector<vector<int>> v(r1, vector<int>(c2));
    for (int i=0; i<r1; i++) {
        for (int j=0; j<c2; j++) {
            for (int k=0; k<c1; k++)
                v[i][j] += arr1[i][k]*arr2[k][j];
        }
    }
    return v;
}