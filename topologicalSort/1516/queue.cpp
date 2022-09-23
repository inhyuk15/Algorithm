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
vector<int> adj[555];
int inorder[555];

int times[555];
int completeTime[555];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> times[i];
        completeTime[i] = times[i];
        int temp;
        while(true){
            cin >> temp;
            if(temp == -1) break;
            temp--;
            adj[temp].push_back(i);
            inorder[i]++;
        }
    }

    vector<int> start;
    for(int i =0; i<n; i++) if(inorder[i] == 0) start.push_back(i);

    queue<int> q;
    for(int i=0; i< start.size(); i++){
        int next = start[i];
        q.push(next);
    }

    while(!q.empty()){
        int here = q.front();
        q.pop();
        int curCost = completeTime[here];
        for(int i =0; i< adj[here].size(); i++){
            int next = adj[here][i];
            inorder[next]--;
            completeTime[next] = max(completeTime[next], curCost + times[next]);

            if(inorder[next] == 0) q.push(next);
        }
        
    }

    for(int i=0; i<n; i++) cout << completeTime[i] << endl;

    return 0;
}


