#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 7000009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], Gcd, M = 1;;
bool trace[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp; a[temp]++;
        if (i == 1) Gcd = temp;
        Gcd = __gcd(Gcd, temp);
        M = max(M, temp);
    }
    // cout << Gcd;
    int res = n, count = 0; 
    for (int i = Gcd+1; i <= M; i++) {
        count = 0;
        if (trace[i] == true) continue;
        for (int j = i; j <= M; j += i) {
            if (trace[j] == true || a[j] == 0 ) continue;
            trace[j]=true;
            count += a[j]; 
        }
        res = min(res, n - count);
    }    
    if (res == n) res = -1;
    cout << res;
}
