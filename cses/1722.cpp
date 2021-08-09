#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int mod = 1e9 + 7;
using namespace std;
struct matrix {
     ll m[3][3] = {};
     matrix() {
          m[1][1] = 0;
          m[1][2] = 1, m[2][2] = 1, m[2][1] = 1;
     }
};
matrix operator*(matrix a, matrix b) {
     matrix res;
     memset(res.m, 0, sizeof(res.m));
     for (int i = 1; i <= 2; i++)
          for (int j = 1; j <= 2; j++)
               for (int k = 1; k <= 2; k++)
                    res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
     return res;
};
matrix Pow(matrix t, ll p) {
     if (p == 1)
          return t;
     matrix m = Pow(t, p / 2);
     if (p % 2 == 0)
          return m * m;
     else
          return (m * m) * t;
}
signed main() {
     ios_base::sync_with_stdio(false), cin.tie(NULL);
     ll n;
     cin >> n;
     if (n == 0) {
          cout << 0;
     } else {
          matrix t;
          t = Pow(t, n);
          cout << t.m[1][2];
     }
}