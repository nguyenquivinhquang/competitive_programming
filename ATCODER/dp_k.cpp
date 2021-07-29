#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;


int n, k, stones[N];
bool dp[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> stones[i];

    for (int i = 0; i <= k; i++)
        for (int j = 1; j <= n; j++) {
            if (i - stones[j] < 0) continue;
            if (dp[i - stones[j]] == false) dp[i] = true;
        }
    if(dp[k]==true) cout<<"First"<<"\n";
    else cout<<"Second"<<"\n";
}
