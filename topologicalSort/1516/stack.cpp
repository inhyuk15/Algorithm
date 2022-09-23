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
int adj[555][555];
int outdegree[555];
int indegree[555];
bool visited[555];
int buildTime[555];
int times[555];
int dfs(int here) {
    // cout << here << " here " << endl;
    int &ret = times[here];
    visited[here] = true;
    
    for(int next = 1; next <=n; next++) {
        if(adj[here][next]) {
            if(visited[next]) ret = max(ret, times[next]);
            else ret = max(ret, dfs(next));
        }
    }
    return ret = ret + buildTime[here];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i =1; i<=n; i++) {
        int t;
        cin >> t;
        buildTime[i] = t;
        while(1) {
            int prev;
            cin >> prev;
            if(prev == -1) break;
            adj[i][prev] = 1;
            outdegree[i]++;
            indegree[prev]++;
        }
    }

    for(int i =1; i<=n; i++) {
        if(indegree[i] == 0) dfs(i);
    }

    for(int i=1; i<=n; i++) {
        cout << times[i] << endl;
    }


    return 0;
}


