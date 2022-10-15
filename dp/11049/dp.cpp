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
int n;
int a[555][2];
int dp[555][555];

// int func(int l, int r) {

// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    for(int i =0; i<n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    memset(dp, INF, sizeof(dp));
    for(int i =0; i<n; i++) dp[i][i] = 0;
    
    for(int j = 1; j<n; j++) {
        for(int i = j-1; i >=0; i--) {
            for(int k = i; k < j; k++) {
                int t = a[i][0] * a[k][1] * a[j][1];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + t);
            }
        }
    }
    cout << dp[0][n-1] << endl;

    return 0;
}

