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

int K, cnt;
int arr[10];
bool isused[10];
bool check[10000000];

void eratos() {
    
    check[0] = true; 
    check[1] = true;
    for (int i=2; i*i<10000000; i++) {
        if (check[i]) continue;
        for (int j=i*i; j<10000000; j+=i)
            check[j] = true;
    }
}

int getNum(int k, const string& numbers) {
    
    int n = 0;
    int p = 1;
    for (int i=k-1; i>=0; i--) {
        n += (numbers[arr[i]]-'0')*p;
        p *= 10;
    } 
    return n;
}

void func(int k, const string& numbers) {
    
    if (k > K) return ;
    int n = getNum(k, numbers);
    if (!check[n]) {
        cnt++;
        check[n] = true;
    }
    
    for (int i=0; i<K; i++) {
        if (isused[i]) continue;
        isused[i] = true;
        arr[k] = i;
        func(k+1, numbers);
        isused[i] = false;
    }
}

int solution(string numbers) {
    
    eratos();
    K = numbers.size();
    func(0, numbers);
    return cnt;
}