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
#include <wchar.h>
#define endl '\n'

typedef long long ll;
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
vector<int> knowTruth;
int truth[55];
vector<int> party[55];
int adj[55][55];

bool visited[55];
void dfs(int here) {
    visited[here] = true;
    for(int next=1; next<=n; next++) {
        if(adj[here][next] && !visited[next]) {
            dfs(next);
            truth[next] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int t = 0;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        knowTruth.push_back(a);
        truth[a] = 1;
    }
    for(int i=0; i<m; i++) {
        cin >> t;
        while(t--) {
            int a;
            cin >> a;
            party[i].push_back(a);
        }
        for(int j =0; j < party[i].size(); j++) {
            int here = party[i][j];
            for(int k = j + 1; k < party[i].size(); k++) {
                int there = party[i][k];
                adj[here][there] = adj[there][here] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i =0; i < knowTruth.size(); i++) {
        int here = knowTruth[i];
        dfs(here);
    }

    for(int i=0; i<m; i++) {
        auto p = party[i];
        bool flag = false;
        for(int j =0; j < p.size(); j++) {
            if(truth[p[j]] == 1) {
                flag = true;
                break;
            }
        }
        if(!flag) cnt++;
    }

    cout << cnt << endl;
    
    return 0;

}
