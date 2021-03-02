#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 1000;

using namespace std;
int n;
ll fact[20];
ll Pow(ll x, ll k, ll m) {
    if (k == 1) return x;
    if (k == 0) return 1;
    ll t = Pow(x, k / 2, m);
    t = (t * t) % m;
    if (k % 2 == 0)
        return t;
    else
        return (t * x) % m;
}
void factorial()  { 

    for (int i = 2; i <= 16; i++) 
        fact[i] = fact[i - 1] * i  ;
} 

ll count(string str)  { 
   map<char, int> temp;
   for (auto c : str) {
       temp[c] ++;
   }
   ll res  = fact[str.length()];
   ll total = 1;
   for (auto v : temp) {
       total = total * fact[v.second];
   }
   return res / total;
} 


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int y;
    ll res = 0;
    string str;
    cin >> n;
    fact[1] = 1;
    factorial();

    for (int i = 1; i <= n; i++) {
        cin >> str >> y;
        ll total = count(str);
        res += Pow(y, total, 2000019);
    }
    cout << res % 50000003;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/