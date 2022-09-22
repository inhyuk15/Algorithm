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
int n, k;
bool inRange(int x) {
    return (0 <= x && x <= 100000);
}

pair<int,int> bfs(int here) {
    vector<int> dist(111111, INF);
    queue<pair<int,int>> q;
    dist[here] = 0;
    q.push({here, 0});
    
    int pathCnt = 0;
    int pathTime = INF;
    while(!q.empty()) {
        int here = q.front().first;
        int cost = q.front().second;
        // cout << here << endl;
        q.pop();
        if(here == k) {
            if(cost <= pathTime) {
                pathCnt++;
                pathTime = cost;
            }
            else break;
        }
        int next = here + 1;
        if(inRange(next) && dist[next] >= cost + 1) {
            q.push({next, cost + 1});
            dist[next] = cost + 1;
        }
        next = here - 1;
        if(inRange(next) && dist[next] >= cost + 1) {
            q.push({next, cost + 1});
            dist[next] = cost + 1;
        }
        next = here * 2;
        if(inRange(next) && dist[next] >= cost + 1) {
            q.push({next, cost + 1});
            dist[next] = cost + 1;
        }
    }
    return {pathTime, pathCnt};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;

    auto p = bfs(n);
    cout << p.first << endl;
    cout << p.second << endl;
    return 0;
}


