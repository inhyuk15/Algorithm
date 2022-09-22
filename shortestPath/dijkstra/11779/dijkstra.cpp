#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>

typedef long long ll;

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;

int adj[1111][1111];
pair<int, vector<int>> bfs(int start, int end) {
    vector<int> dist(1111, INF);
    priority_queue<pair<int,int>> pq;
    vector<int> parent(1111, -1);
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int here = p.second, cost = -p.first;
        if(dist[here] < cost) continue;
        for(int next = 1; next<=n; next++) {
            // if(adj[here][next]) {
                int nextCost = adj[here][next] + cost;
                if(nextCost < dist[next]) {
                    pq.push({-nextCost, next});
                    dist[next] = nextCost;
                    parent[next] = here;
                }
            // }
        }
    }
    vector<int> path;
    int startPoint = end;
    while(startPoint != -1) {
        path.push_back(startPoint);
        startPoint = parent[startPoint];
    }
    reverse(path.begin(), path.end());
    return {dist[end], path};
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> n >> m;
    memset(adj, INF, sizeof(adj));
    for(int i =0; i<m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start][end] = min(adj[start][end], cost);
    }
    int start, end;
    cin >> start >> end;

    auto ans = bfs(start, end);
    auto path = ans.second;
    auto dist = ans.first;
    cout << dist << endl;
    cout << path.size() << endl;
    for(auto p : path) cout << p << " ";

	return 0;
}
