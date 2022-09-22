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
char board[22][22];
int dist[22][22][22][22];
const int dy[4] = {0,0,-1,1};
const int dx[4] = {1,-1,0,0};
int sy, sx, ey, ex;
int by, bx;

bool isRange(int y, int x) {
    return (y < n && x < m && y >=0 && x >= 0);
}
bool hasReached(int y, int x) {
    return y == ey && x == ex;
}

// {y, x} is first move, then {ay, ax}
// call move(0) move(1) move(0) move(1)
// return hasReached, reachPoint
pair<bool, pair<int,int>> move(int y, int x, int ay, int ax,int dir) {
    int hereY = y, hereX = x;
    bool reached = false;
    while(isRange(hereY + dy[dir], hereX + dx[dir])) {
        int nextY = hereY + dy[dir], nextX = hereX + dx[dir];
        // meet wall or meet another color
        if(board[nextY][nextX] == '#'
        || (nextY == ay && nextX == ax)) {
            break;
        }
        // if reach
        if(hasReached(nextY, nextX))  {
            reached = true;
        }
        hereY += dy[dir], hereX += dx[dir];
    }
    return {reached, {hereY, hereX}};
}

int bfs(pair<int,int> s, pair<int,int> e, pair<int,int> b) {
    memset(dist, INF, sizeof(dist));
    // queue<y, x>
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{s.first, s.second}, {b.first, b.second}});
    dist[s.first][s.second][b.first][b.second] = 0;

    int ret = INF;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        auto red = p.first, blue = p.second;
        int cost = dist[red.first][red.second][blue.first][blue.second];
        for(int i =0; i<4; i++) {
            auto nrp1 = move(red.first, red.second, blue.first, blue.second, i);
            auto nr1 = nrp1.second;
            bool redReached1 = nrp1.first;
            if(redReached1) {
                nr1 = {0, 0};
            }
            auto nbp1 = move(blue.first, blue.second, nr1.first, nr1.second, i);
            auto nb1 = nbp1.second;
            bool blueReached1 = nbp1.first;

            auto nrp2 = move(nr1.first, nr1.second, nb1.first, nb1.second, i);
            auto nr2 = nrp2.second;
            bool redReached2 = nrp2.first;
            if(redReached2) {
                nr2 = {0, 0};
            }
            auto nbp2 = move(nb1.first, nb1.second, nr2.first, nr2.second, i);
            auto nb2 = nbp2.second;
            bool blueReached2 = nbp2.first;

            auto nr = nr2;
            auto nb = nb2;
            bool redReached = redReached1 || redReached2;
            bool blueReached = blueReached1 || blueReached2;
            
            if(blueReached) continue;
            if(redReached) {
                ret = min(ret, cost + 1);
                continue;
            }

            if(dist[nr.first][nr.second][nb.first][nb.second] > cost + 1) {
                dist[nr.first][nr.second][nb.first][nb.second] = cost + 1;
                q.push({{nr.first, nr.second}, {nb.first, nb.second}});
            }
        }
    }
    return ret > 10 ? -1 : ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j =0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                sy = i, sx = j;
            }
            if(board[i][j] == 'O') {
                ey = i, ex = j;
            }
            if(board[i][j] == 'B') {
                by = i, bx = j;
            }
        }
    }

    cout << bfs({sy, sx}, {ey, ex}, {by, bx});



    return 0;

}


