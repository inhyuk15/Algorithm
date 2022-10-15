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
int a[2222][2];
int dp[2222];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c >> n;
    
    for(int i =0; i<n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = INF;
    for(int i = 0; i < n; i++) dp[a[i][1]] = min(dp[a[i][1]], a[i][0]);
    for(int i = 0; i <=1000; i++) {
        for(int j =0; j < n; j++) {
            if(i - a[j][1] >= 0) {
                dp[i] = min(dp[i], dp[i-a[j][1]] + a[j][0]);
            }
        }
        for(int j =i; j <= 1000; j++) dp[i] = min(dp[i], dp[j]);
    }
    cout << dp[c] << endl;
    return 0;
}

