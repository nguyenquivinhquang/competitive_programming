#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int ll 
const int N = 1000;

using namespace std;
int n, m, res = 0;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int temp;
    vector<int> a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    ll total = 0, c = 0;
    for (auto v : a) {
        total += v;
        if (total > m) {
            c++;
            total = v;
        }
    }
    
    int ss = 0, ee = n - 1;
    for (; ss <= ee; ee--) {
        ll total = a[ee];
        while (total <= m && ss < ee) {
            if (total + a[ss] <= m) total += a[ss++]; 
            else break;
        }
        res++;
    }
    
    
    cout << min(res, c);
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/