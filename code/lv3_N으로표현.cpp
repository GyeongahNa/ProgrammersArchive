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

vector<set<int>> res(10);

int solution(int N, int number) {

    res[1].insert(N);

    for (int m=2; m<=8; m++) {

        int p = 1;
        int num = 0;
        for (int i=1; i<=m ;i++) {
            num += (N*p);
            p *= 10;
        }
        res[m].insert(num);

        for (int i=1; i<m; i++) {
            for (auto num1 : res[i]) {
                for (auto num2 : res[m-i]) {
                    res[m].insert(num1+num2);
                    res[m].insert(num1-num2);
                    res[m].insert(num1*num2);
                    if (num2) res[m].insert(num1/num2);
                }
            }
        }
    }

    for (int m=1; m<=8; m++) {
        if (find(res[m].begin(), res[m].end(), number) != res[m].end()) 
            return m;
    }
    return -1;
}