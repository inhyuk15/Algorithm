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
vector<int> knowTruth;
int truth[55];
int party[55];
int parent[55];
int rankk[55];
int cnt[55];
int find(int u) {
    if(u == parent[u]) return u;
    return find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(truth[v]) parent[u] = v;
    else parent[v] = u;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int t = 0;
    for(int i=1; i<=n; i++) {
        rankk[i] = 1;
        parent[i] = i;
        cnt[i] = 1;
    }
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        knowTruth.push_back(a);
        truth[a] = 1;
    }

    for(int i=0; i<m; i++) {
        cin >> t;
        int a;
        cin >> a;
        t--;
        while(t--) {
            int b;
            cin >> b;
            merge(a, b);
        }
        party[i] = find(a);
    }

    
    int cnt = 0;
    for(int i=0; i<m; i++) {
        if(truth[find(party[i])]) cnt++;

    }
    cout << m - cnt;

    
    
    return 0;

}


