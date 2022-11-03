#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl '\n'

typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;

int dp[2222][2222];
int dp2[2222];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // for(int i =0; i < n; i++) {
    //     for(int j =0; j<m; j++) {
    //         if(s1[i] == s2[j]) {
    //             dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
    //         }
    //         dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
    //         dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
    //     }
    // }
    int ret = 0;
    for(int i =0; i <n; i++) {
        int cur = 0;
        for(int j =0; j<m; j++) {
            if(cur < dp2[j]) cur = dp2[j];
            else if(s1[i] == s2[j]) {
                dp2[j] = cur + 1;
                ret = max(ret, dp2[j]);
            }
        }
    }

    // cout << dp[n][m];
    cout << ret;

    
    return 0;
}
