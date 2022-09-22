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

vector<int> dijkstra1(int start) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int here = p.second, cost = -p.first;
        for(int next = 1; next <=n; next++) {
            int nextCost = cost + adj[here][next];
            if(adj[here][next] && dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
    return dist;
}

vector<int> dijkstra2(int start) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int here = p.second, cost = -p.first;
        for(int next = 1; next <=n; next++) {
            int nextCost = cost + adj2[here][next];
            if(adj2[here][next] && dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({-nextCost, next});
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

    auto v1 = dijkstra1(x);
    for(int i =1; i<=n; i++) {
        for(int j =1; j<=n; j++) {
            adj2[j][i] = adj[i][j];
        }
    }
    auto v2 = dijkstra2(x);
    int ret = 0;
    for(int i =1; i<=n; i++) {
        ret = max(ret, v1[i] + v2[i]);
    }
    cout << ret << endl;
    
    return 0;

}


