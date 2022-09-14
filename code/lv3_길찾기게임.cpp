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

vector<int> vpre, vpost;

void traverse(int cur, vector<int> vchild, vector<vector<int>> nodeinfo) {

    vpre.push_back(cur+1);

    int x = nodeinfo[cur][0];
    int y = nodeinfo[cur][1];

    vector<int> leftsub, rightsub;

    for (int c : vchild) {
        int a = nodeinfo[c][0];
        int b = nodeinfo[c][1];
        if (a < x) leftsub.push_back(c);
        else rightsub.push_back(c);
    }

    auto cmp = [&nodeinfo](int a, int b){return nodeinfo[a][1] > nodeinfo[b][1];};
    sort(leftsub.begin(), leftsub.end(), cmp);
    sort(rightsub.begin(), rightsub.end(), cmp);

    if ((int)leftsub.size()> 0) {
        int next = leftsub[0];
        leftsub.erase(leftsub.begin());
        traverse(next, leftsub, nodeinfo);
    }
    if ((int)rightsub.size() > 0) {
        int next = rightsub[0];
        rightsub.erase(rightsub.begin());
        traverse(next, rightsub, nodeinfo);
    }

    vpost.push_back(cur+1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    vector<int> child;
    for (int i=0; i<(int)nodeinfo.size(); i++) 
        child.push_back(i);

    auto cmp = [&nodeinfo](int a, int b){return nodeinfo[a][1] > nodeinfo[b][1];};
    sort(child.begin(), child.end(), cmp);

    int root = child[0];
    child.erase(child.begin());
    traverse(root, child, nodeinfo);

    vector<vector<int>> ans;
    ans.push_back(vpre);
    ans.push_back(vpost);
    return ans;
}