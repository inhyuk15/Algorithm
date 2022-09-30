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
#include <cstdlib>
#define endl '\n'

typedef long long ll;
using namespace std;

const int INF = 0x3f3f3f3f;
int n;
vector<int> adj[3333];
int visited[3333];
int finished[3333];
int p[3333];
vector<int> path;
int cnt = 0;
vector<int> dist;

void bfs() {
    queue<int> q;
    for(auto p : path) q.push(p);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i =0; i <adj[here].size(); i++) {
            int next = adj[here][i];
            if(dist[next] == INF) {
                dist[next] = dist[here] + 1;
                q.push(next);
            }
        }
    }
}

// 그래프에서 cycle 찾기
void func(int here) {
    visited[here] = true;
    for(int i =0; i < adj[here].size(); i++) {
        int next = adj[here][i];
        if(!visited[next]) {
            p[next] = here;
            func(next);
        }
        else if(finished[next]) {
            for(int i = next; i != here; i = p[i]) {
                path.push_back(i);
            }
            path.push_back(here);
        }
    }
    finished[here] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    // 간선이 n개임
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    func(1);
    dist = vector<int>(n+1, INF);
    for(auto p : path) dist[p] = 0;
    bfs();
    for(int i =1; i<=n; i++) cout << dist[i] << " ";

    return 0;
}


