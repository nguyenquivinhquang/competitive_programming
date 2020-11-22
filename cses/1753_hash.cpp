//https://cses.fi/problemset/task/1753
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000009;
const int mod = 1e9 + 9;
const int P = 311;
using namespace std;
string a, b;
ll Pow[N], h[N], res = 0;
void ComputePow() {
    Pow[0] = 1;
    for (int i = 1; i < N; i++)
        Pow[i] = (Pow[i - 1] * P) % mod;
}
ll hasing(string &s) {
    ll hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash + (s[i] - 'a' + 1) * Pow[i]) % mod;
        h[i] = hash;
    }
    return hash;
}
ll getHash(int l, int r){
    return (h[r] - h[l - 1] + mod) % mod;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    //freopen("input.txt","r", stdin);
    ComputePow();
    cin >> a >> b;
    ll hash = hasing(b);
    ll si = b.length();
    a = "!" + a;
    // cout << hash << endl;
    hasing(a);
    // for (int i = 1; i < a.length(); i++)
    //     cout << h[i] << " ";
    for (int i = 1; i < a.length(); i++){
        if (i + si - 1 >= a.length()) break;
        if ( (getHash(i, i + si - 1) == (hash * Pow[i]) % mod )) res++;
    }
    cout << res << endl;

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
