#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
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

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data, Node* prev, Node* next) : data(data), prev(prev), next(next) {}
};

void cmdU(Node** pcur, int x) {
    for (int i=0; i<x; i++) *pcur = (*pcur)->prev;
}

void cmdD(Node** pcur, int x) {
    for (int i=0; i<x; i++) *pcur = (*pcur)->next;
}

void cmdC(Node** pcur, stack<Node*>& st) {

    st.push(*pcur);
    if ((*pcur)->prev != NULL)
        (*pcur)->prev->next = (*pcur)->next;
    if ((*pcur)->next != NULL)
        (*pcur)->next->prev = (*pcur)->prev;
    if ((*pcur)->next == NULL) (*pcur) = (*pcur)->prev;
    else (*pcur) = (*pcur)->next;
}

void cmdZ(stack<Node*>& st) {

    Node* tmp = st.top();
    st.pop();
    if (tmp->prev != NULL)
        tmp->prev->next = tmp;
    if (tmp->next != NULL)
        tmp->next->prev = tmp;
}

string solution(int n, int k, vector<string> cmd) {

    Node* node = new Node(0, NULL, NULL);
    Node* cur = node;
    stack<Node*> st;

    for (int i=1; i<n; i++) {
        node->next = new Node(i, node, NULL);
        node = node->next;
    }

    for (int i=0; i<k; i++) cur = cur->next;

    for (auto s : cmd) {
        char c;
        int x;
        sscanf(s.c_str(), "%c %d", &c, &x);
        if (c == 'U') cmdU(&cur, x);
        else if (c == 'D') cmdD(&cur, x);
        else if (c == 'C') cmdC(&cur, st);
        else if (c == 'Z') cmdZ(st); 
    }

    string ans = string(n, 'O');
    while (!st.empty()) {
        ans[st.top()->data] = 'X';
        st.pop();
    }
    return ans;
}