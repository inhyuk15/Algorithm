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
int adj[111][111];

int bfs(int start, int end) {
    vector<int> dist(n+1, INF);
    queue<pair<int,int>> q;
    q.push({start, 0});
    dist[start] = 0;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int here = p.first, cost = p.second;
        for(int next = 1; next <=n; next++) {
            if(adj[here][next]) {
                if(dist[next] == INF) {
                    dist[next] = cost + 1;
                    q.push({next, cost + 1});
                }
            }
        }
    }
    return dist[end] == INF ? -1 : dist[end];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int start, end;
    cin >> start >> end;
    cin >> m;
    for(int i =0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    cout << bfs(start, end);
    return 0;

}


