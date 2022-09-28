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
vector<int> arr;
int visited[111111];
int finished[111111];
void dfs(int here, vector<int>& path) {
    visited[here]++;
    int next = arr[here];
    if(visited[next] == -1) {
        dfs(next, path);
    }
    else if(finished[next] == -1) {
        for(int i = next; i != here; i = arr[i]) {
            path.push_back(i);
        }
        path.push_back(here);
    }
    finished[here] = true;
}

// arr에 있는 사이클에 속하지 않는 수 구하기
int func() {
    // cycle cnt
    int ret = 0;
    memset(visited, -1, sizeof(visited));
    memset(finished, -1, sizeof(finished));
    for(int i=1; i<=n; i++) {
        vector<int> path;
        if(visited[i] == -1) {
            dfs(i, path);
            ret += path.size();
        }
    }
    return n - ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        arr = vector<int>(n+1);
        for(int i =1; i<=n; i++) {
            cin >> arr[i];
        }
        cout << func() << endl;
    }
    return 0;

}


