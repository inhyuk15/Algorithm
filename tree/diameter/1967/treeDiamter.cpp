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
int startPoint;
int t = -1;
vector<pair<int,int>> adj[11111];
bool visited[11111];
int dfs(int here, int sum) {
    visited[here] = true;
    if(sum > t) {
        t = sum;
        startPoint = here;
    }
    int ret = sum;
    for(int i=0; i < adj[here].size(); i++) {
        int next = adj[here][i].first;
        int dist = adj[here][i].second;
        if(!visited[next]) {
            ret = max(ret, dfs(next, sum + dist));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i< n-1; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    // cout << dfs(1, 0) << endl;
    dfs(1, 0);
    // cout << "start " << startPoint << endl;
    memset(visited, false, sizeof(visited));
    cout << dfs(startPoint, 0);

    return 0;

}


