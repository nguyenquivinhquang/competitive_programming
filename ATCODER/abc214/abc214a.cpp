#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    if (n < 126) cout << 4;
    else if (n < 212) cout << 6;
    else cout << 8;
}
