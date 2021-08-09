//https://codeforces.com/contest/221/problem/C
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100050;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, a[N], b[N], diff = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + 1 +n);
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i]) diff++;
    if (diff <= 2) cout <<"YES"; else cout <<"NO";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/