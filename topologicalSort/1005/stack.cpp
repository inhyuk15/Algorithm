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

int times[1111];
int buildTime[1111];
int adj[1111][1111];
int n, k;
bool visited[1111];
int inorder[1111];
int dfs(int here) {
    // cout << here << endl;
    visited[here] = true;
    int& ret = times[here];
    for(int next = 1; next <=n; next++) {
        if(adj[here][next] == 0) continue;
        if(!visited[next]) {
            ret = max(ret, dfs(next));
        }
        else ret = max(ret, times[next]);
    }
    return ret = ret + buildTime[here];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(buildTime, 0, sizeof(buildTime));
        memset(times, 0, sizeof(times));
        for(int i =1; i<=n; i++) {
            cin >> buildTime[i];
        }
        memset(adj, 0, sizeof(adj));
        for(int i =0; i<k; i++) {
            int a, b;
            cin >> a >> b;
            adj[b][a]=1;
        }

        // for(int i =1; i<=n; i++) {
        //     if(inorder[i] == 0) {
        //         dfs(i);
        //     }
        // }
        memset(visited, false, sizeof(visited));
        int dst;
        cin >> dst;
        cout << dfs(dst) << endl;
    }

    return 0;

}


