#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<limits>
#include<cstring>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int n;
vector<int> adj[11111];
int inorder[11111];
int times[11111];

int costSum[11111];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> times[i];
        int prior;
        int cnt;
        cin >> cnt;
        while(cnt--){
            cin >> prior;
            prior--;
            adj[prior].push_back(i);
            inorder[i]++;
        }
    }

    queue<int> q;
    vector<int> start;

    for(int i=0; i< n; i++) if(inorder[i] == 0){
        q.push(i);
        costSum[i] = times[i];
        inorder[i]--;
    }

    while(!q.empty()){
        int here = q.front();
        q.pop();
        int nextCost = 0;
        for(int i=0; i< adj[here].size(); i++){
            int next = adj[here][i];
            inorder[next]--;

            costSum[next] = max(costSum[next], costSum[here] + times[next]);

            if(inorder[next] == 0){
                q.push(next);
            }
        }
    }

    int ret =0;
    for(int i=0; i<n; i++) ret = max(ret, costSum[i]);

    cout << ret << endl;

    return 0;
}


