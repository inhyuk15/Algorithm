#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<regex>
#include<queue>
#include<set>
#include <cmath>
#define endl '\n'

typedef long long ll;
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;

vector<vector<int>> adj;
int v, e;
int visited[22222];
int cnt = 0;
bool flag = true;
void dfs(int here, int cnt) {
    visited[here] = (cnt) % 2;
    for(int i=0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(visited[next] == -1) {
            dfs(next, (cnt + 1) % 2);
        }
        else if(visited[next] == cnt % 2) {
            flag = false;
            return;
        }
    }
}
bool check() {
    flag = true;
    memset(visited, -1, sizeof(visited));
    for(int i =1; i<=v; i++) {
        if(visited[i] == -1) {
            dfs(i, 0);
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> v >> e;
        adj = vector<vector<int>>(v+1, vector<int>());
        for(int i=0; i<e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(check())
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    
    
    return 0;

}


