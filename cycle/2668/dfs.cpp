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

int n;
int adj[111][111];
int visited[111];
bool cycle[111];
int parent[111];
bool finished[111];
void dfs(int here, vector<int>& path) {
    // cout << here << "here" << endl;
    visited[here] = true;
    for(int next = 1; next <= n; next++) {
        if(adj[here][next]) {
            if(!visited[next]) {
                parent[here] = next;
                dfs(next, path);
            }
            else if(!finished[next]) {
                for(int i = next; i != here; i = parent[i]) {
                    path.push_back(i);
                }
                path.push_back(here);
            }
        }
    }
    finished[here] = true;
}

// adj에서 사이클을 이루는 원소들 반환
vector<int> func() { 
    vector<int> ret;
    for(int i =1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i, ret);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i =1; i<=n; i++) {
        int j;
        cin >> j;
        adj[i][j] = 1;
    }
    auto ret = func();
    
    // for(auto i : ret) {
    //     cout << i << endl;
    // }
    // cout << " -----------" << endl;
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    cout << ret.size() << endl;
    for(auto i : ret) {
        cout << i << endl;
    }
    return 0;

}


