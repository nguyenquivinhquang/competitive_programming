#include <bits/stdc++.h>
 
#define ll long long
#define pp pair<int, int>
 
const int N = 100009;
 
using namespace std;
 
string a;
int dp[N][9];
string c = "chokudai";
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> a;
    for (int i = 0; i < a.size(); i++) dp[i][0]=1;
 
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j < 9; j++) {
            if (a[i-1] == c[j-1]) 
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j];
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[a.size()][8];
}