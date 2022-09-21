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
int n, m, x;
int adj[1111][1111];
int adj2[1111][1111];

vector<int> bfs(int start) {
    vector<int> dist(n+1, INF);
    queue<pair<int,int>> q;
    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int here = p.first, cost = p.second;
        for(int next = 1; next <=n; next++) {
            int nextCost = cost + adj[here][next];
            if(adj[here][next] && dist[next] > nextCost) {
                dist[next] = nextCost;
                q.push({next, nextCost});
            }
        }
    }
    return dist;
}

vector<int> bfs2(int start) {
    vector<int> dist(n+1, INF);
    queue<pair<int,int>> q;
    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int here = p.first, cost = p.second;
        for(int next = 1; next <=n; next++) {
            int nextCost = cost + adj2[here][next];
            if(adj2[here][next] && dist[next] > nextCost) {
                dist[next] = nextCost;
                q.push({next, nextCost});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x;
    for(int i =0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(adj[a][b]) adj[a][b] = min(adj[a][b], c);
        else adj[a][b] = c;
    }

    auto v1 = bfs(x);
    for(int i =1; i<=n; i++) {
        for(int j =1; j<=n; j++) {
            adj2[j][i] = adj[i][j];
        }
    }
    auto v2= bfs2(x);
    int ret = 0;
    for(int i =1; i<=n; i++) {
        ret = max(ret, v1[i] + v2[i]);
    }
    cout << ret << endl;
    
    return 0;

}


