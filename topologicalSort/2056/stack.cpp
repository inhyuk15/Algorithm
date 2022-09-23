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
int processTime[11111];
vector<int> adj[11111];
bool visited[11111];
int indegree[11111];
int outdegree[11111];
int times[11111];

int dfs(int here) {
    // cout << "here" << here << endl;
    visited[here] = true;
    int& ret = times[here];
    if(outdegree[here] == 0) {
        return ret = processTime[here];
    }

    for(int i =0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if (visited[next]) {
            ret = max(ret, times[next]);
        }
        else ret = max(ret, dfs(next));
    }
    return ret = ret + processTime[here];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i =1; i<=n; i++) {
        cin >> processTime[i];
        int t;
        cin >> t;
        for(int j =0; j<t; j++) {
            int k;
            cin >> k;
            adj[i].push_back(k);
            indegree[k]++;
            outdegree[i]++;
        }
    }
    int ret = 0;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) {
            // cout << "this " << i << endl;
            ret = max(ret, dfs(i));
        }
    }
    cout << ret << endl;

    return 0;
}


