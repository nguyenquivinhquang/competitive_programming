#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int a[N], n, p;
ll fact[N]; bool used[N];
void sub1() {

    ll res = 0; 
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j ++) count += j < a[i] && used[j] == false;
        res += fact[n-i] * count;
        used[a[i]] = true;
    }
    cout << res + 1 << "\n";
}
void sub2() {
    memset(used, false, sizeof(used));
    ll res = p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (used[j] == true) continue;
            if ( res >  fact[n-i]) res -= fact[n-i];
            else {
                cout << j << " ";
                used[j] = true;
                break;
            }
        }

    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    // freopen("E:\\Competitive_Programming\\oj\\input.txt", "r", stdin);
    fact[1] = 1; fact[0] = 1;
    for (int i = 2; i <= 14; i++) fact[i] = fact[i-1]*i;
    while (cin >> a[++n]){};
    p = a[--n]; n--;
    sub1();
    sub2();
}
