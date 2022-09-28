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
int n, m;

int block[22][22];
const int dy[4] = {0,0,-1,1};
const int dx[4] = {-1,1,0,0};

int dist[22][22];
// bfs로 가장 가까운 것들 중 위쪽, 왼쪽인거 반환
pair<pair<int,int>,int> findNextPos(int y, int x, int curSize) {
    vector<pair<int,int>> ret;
    memset(dist, INF, sizeof(dist));
    queue<pair<int,int>> q;
    dist[y][x] = 0;
    q.push({y, x});
    int minCost = INF;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int hy = p.first;
        int hx = p.second;
        
        if(block[hy][hx] != 0 && block[hy][hx] < curSize && (hy != y || hx != x)) {
            if(dist[hy][hx] < minCost) {
                ret.clear();
                ret.push_back({hy, hx});
                minCost = dist[hy][hx];
            }
            else if(dist[hy][hx] == minCost) {
                ret.push_back({hy, hx});
            }
        }
        for(int i =0; i<4; i++) {
            int ny = hy + dy[i];
            int nx = hx + dx[i];
            if(ny < 0 || nx < 0 || ny >=n || nx >= n) continue;
            if(block[ny][nx] > curSize) continue;
            if(dist[ny][nx] == INF) {
                dist[ny][nx] = dist[hy][hx] + 1;
                q.push({ny, nx});
            }
           
        }
    }
    if(y == 4 && x ==1) {
        // cout << " sz " << curSize << endl;

    }

    sort(ret.begin(), ret.end());
    if(ret.empty()) return {{-1, -1}, -1};
    return {ret[0], dist[ret[0].first][ret[0].second]};
}

// (sy, sx)부터 시작해서 잡을 수 있는 모든 걸 잡는 최단거리
// but 거리가 가장 가깝고 그런게 많으면 가장 위, 왼쪽부터 먼저 탐색
int func(int sy, int sx) {
    int ret = 0;
    int sz = 2;
    auto a = findNextPos(sy, sx, sz);
    pair<int,int> nextPos = a.first;
    block[nextPos.first][nextPos.second] = 0;
    int nextCost = a.second;
    int cnt = 1;
    while(nextPos.first != -1) {
        ret += nextCost;
        a = findNextPos(nextPos.first, nextPos.second, sz);
        nextPos = a.first;
        nextCost = a.second;
        block[nextPos.first][nextPos.second] = 0;
        cnt++;
        if(cnt == sz) {
            cnt = 0;
            sz++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    int sy, sx;
    for(int i=0; i<n; i++) {
        for(int j =0; j<n; j++) {
            cin >> block[i][j];
            if(block[i][j] == 9) {
                sy = i, sx = j;
                block[i][j] = 0;
            }
        }
    }

    cout << func(sy, sx);
    // auto a = findNextPos(sy, sx, 2);
    // cout << a.size() << " sz "<< endl;
    // for(auto aa : a) cout << aa.first << " , " << aa.second << " ";
    return 0;

}


