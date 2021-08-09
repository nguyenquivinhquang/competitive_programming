#include <bits/stdc++.h>
#define fi first
#define se second
#define max3(a, b, c) max(a, max(b, c))
#define writef(a, n) cout << fixed << setprecision(n) << a


using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll a[10];
ll bigger[10][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("t.inp", "r", stdin);
    for (int i = 0 ; i < 5 ; i++) {
        a[i] = i;
    }
    for (int i = 0 ; i < 5 ; i++) {
        string s;
        cin >> s;
        ll u = ll(s[0]-'A');
        ll v = ll(s[2]-'A');
        if (s[1] == '>') {
            bigger[u][v] = 1;
            bigger[v][u] = 2;
        } else {
            bigger[v][u] = 1;
            bigger[u][v] = 2;
        }
    }
    do {
        bool ok = 1;
        for (int i = 0 ; i < 4 ; i++) {
            for (int j = i+1 ; j < 5 ; j++) {
                ok &= (((bigger[a[j]][a[i]] == 1) && (bigger[a[i]][a[j]] == 2)) || (bigger[a[j]][a[i]] == 0));
            }
        }
        if (ok) {
            for (int i = 0 ; i < 5 ; i++) {
                cout << char(a[i] + 'A');
            }
            return 0;
        }
    } while (next_permutation(a, a+5));
    cout << "impossible";
    return 0;
}
