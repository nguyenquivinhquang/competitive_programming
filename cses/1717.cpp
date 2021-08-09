#include <bits/stdc++.h>

#define ll long long
#define int long long
#define pp pair<int, int>

const int N = 1000019;
const long long mod = 1e9 + 7;
using namespace std;

int f[N], fac[N];
signed main() {
     ios_base::sync_with_stdio(false), cin.tie(NULL);
     f[1] = 0, f[2] = 1;
     fac[0] = fac[1] = 1;
     int n;
     cin >> n;
     //  for (int i = 2; i <= n; i++)
     //       fac[i] = (fac[i - 1] * i) % mod;
      for (int i = 3; i <= n; i++) {
           f[i] = (i - 1) * (f[i - 2] + f[i - 1]);
           f[i] %= mod;
      }
      cout << f[n];
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/