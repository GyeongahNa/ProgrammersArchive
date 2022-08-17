#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

int solution(vector<int> numbers, int target) {

    int cnt = 0;
    int n = numbers.size();

    for (int i=0; i<(1<<n); i++) {
        int sum = 0, tmp = i;
        for (int j=0; j<n; j++) {
            if (tmp%2) sum += numbers[j];
            else sum += (-1)*numbers[j];
            tmp /= 2;
        }
        if (sum == target) cnt++;
    }
    return cnt;
}