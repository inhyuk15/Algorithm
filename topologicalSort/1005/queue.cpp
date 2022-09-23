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
int n, k;
int times[1111];
vector<int> adj[1111];
int inorder[1111];

int costSum[1111];

int func(int dst){
    vector<int> start;
    for(int i =0; i<n; i++){
        if(inorder[i] == 0) start.push_back(i);
    }

    queue<int> q;
    int ret = 0;
    for(int i=0; i< start.size(); i++){
        int next = start[i];
        costSum[next] = times[next];
        if(next == dst) return times[next];
        q.push(next);
    }
    
    int nextCost = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int i =0; i< adj[here].size(); i++){
            int next = adj[here][i];
            inorder[next]--;
            costSum[next] = max(costSum[next], costSum[here] + times[next]);

            if(inorder[next] == 0){
                q.push(next);
            }
        }
    }

    return costSum[dst];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(times,0, sizeof(times));
        memset(inorder, 0, sizeof(inorder));
        memset(costSum, 0, sizeof(costSum));
        for(int i=0; i< n; i++) adj[i].clear();


        for(int i= 0; i<n; i++){
            cin >> times[i];
        }

        for(int i=0; i<k; i++){
            int a,b;
            cin >> a >> b;
            a--,b--;
            adj[a].push_back(b);
            inorder[b]++;
        }

        int dst;
        cin >> dst;
        dst--;

        cout << func(dst) << endl;

    }
    return 0;
}

