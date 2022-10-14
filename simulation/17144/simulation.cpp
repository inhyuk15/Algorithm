#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>
#include <queue>
#include <set>
#include <cmath>
#include <deque>
#define endl '\n'

typedef long long ll;
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, t;
vector<pair<int, int>> sPos;
int block[111][111];

// 공기청정기 돌리기
// dir == 1 then closewise else anti-clockwise
deque<pair<int, int>> airFresher(pair<int, int> pos, int dir)
{
    deque<pair<int, int>> path;
    int y = pos.first;
    int x = pos.second;
    int sy = y;
    int sx = x;
    for (int i = 0; i < m; i++)
    {
        path.push_back({y, x});
        x++;
        if (x == m - 1 || x >= m - 1)
            break;
    }
    if (dir == 0)
    {
        for (int i = 0; i < n; i++)
        {
            path.push_back({y, x});
            y--;
            if (y == 0 || y <= 0) break;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            path.push_back({y, x});
            y++;
            if (y == n - 1 || y >= n-1) break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        path.push_back({y, x});
        x--;
        if (x == 0 || x <= 0)
            break;
    }
    if (dir != 0)
    {
        for (int i = 0; i < n; i++)
        {
            path.push_back({y, x});
            y--;
            if (y == sy || y <= 0)
                break;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            path.push_back({y, x});
            y++;
            if (y == sy || y >= n-1)
                break;
        }
    }
    if (!path.empty()) path.pop_front();
    int curDust = block[sy][sx];
    int nextDust = 0;
    for(auto p : path) {
        nextDust = block[p.first][p.second];
        block[p.first][p.second] = curDust;
        curDust = nextDust;
    }
    return path;
}

int total_dust = 0;

const int dy[4] = {0,0,-1,1};
const int dx[4] = {1,-1,0,0};

int addBlock[111][111];

void spread() {
    for(int y=0; y<n; y++) {
        for(int x=0; x<m; x++) {
            vector<pair<int,int>> path;
            int val = block[y][x] / 5;
            for(int k =0; k<4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                bool flag = false;
                if(ny < 0 || nx < 0 || ny >=n || nx >= m) flag = true;
                for(auto s : sPos)
                    if(s.first == ny && s.second == nx) flag = true;
                if(flag) continue;
                path.push_back({ny, nx});
            }
            for(auto p : path) {
                addBlock[p.first][p.second] += val;
            }
            block[y][x] -= (path.size() * val);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j =0; j<m; j++) {
            block[i][j] += addBlock[i][j];
            addBlock[i][j] = 0;
        }
    }
    // memset(addBlock, 0, sizeof(addBlock));
}

// t초후의 먼지 총양 출력
int func(int t)
{
    while(t--) {
        spread();
        airFresher(sPos[0], 0);
        airFresher(sPos[1], 1);
        // airCleaner();
    }
    int ret = 0;
    for(int i=0; i<n; i++) {
        for(int j =0; j<m; j++) {
            ret += block[i][j];
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    int ttt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> block[i][j];
            if(block[i][j] == -1) {
                sPos.push_back({i, j});
                block[i][j] = 0;
            }
            ttt += block[i][j];
        }
    }
    // cout << ttt << endl;

    // cout << "---------------" << endl;
    cout << func(t) << endl;
    // for(int i=0; i<n; i++) {
    //     for(int j =0; j<m; j++) {
    //         cout << block[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << " ,,,,,,,,,,,,,,," << endl;
    // int tt = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j =0; j<m; j++) {
    //         cout << addBlock[i][j] << " ";
    //         tt += addBlock[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << tt << endl;

    return 0;
}

