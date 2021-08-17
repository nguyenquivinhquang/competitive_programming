#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 3001;

using namespace std;

int dp[N][N];
string a, b;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> a >> b;
   
    a = '1' + a; b = '1' + b;
    for (int i = 1; i < a.length(); i++)
        for (int j = 1; j < b.length(); j++) {
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + 1);
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    string str;
    int x = a.size() - 1, y = b.size() - 1;

    while (x > 0 && y > 0) {
        // cerr << x << " " << y << endl;
        if (dp[x][y] == dp[x][y - 1]) y--;
        else if (dp[x][y] == dp[x-1][y]) x--;
        else {
            str.push_back(a[x]);
            x--, y--;
        }
    }
    reverse(str.begin(), str.end());
    cout << str;
}
