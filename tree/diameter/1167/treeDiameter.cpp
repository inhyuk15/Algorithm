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

vector<pair<int,int>> adj[111111];
int n;
bool visited[111111];
int startPoint = -1;
int t;
// here 에서 가장 먼 점 반환
int dfs(int here, int curDist) {
    visited[here] = true;
    if(curDist > t) {
        t = curDist;
        startPoint = here;
    }
    int ret = curDist;
    for(int i =0; i < adj[here].size(); i++) {
        int next = adj[here][i].first;
        if(!visited[next]) {
            int dist = adj[here][i].second;
            int nextDist = dfs(next, curDist + dist);
            if(ret < nextDist) {
                ret = nextDist;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        int u, v, l;
        cin >> u;
        cin >> v;
        while(v != -1) {
            cin >> l;
            adj[u].push_back({v, l});
            cin >> v;
        }
    }
    // cout <<  dfs(1, 0) << endl;
    dfs(1, 0);
    // cout << startPoint << endl;
    memset(visited, false, sizeof(visited));
    cout << dfs(startPoint, 0);
    
    return 0;

}


