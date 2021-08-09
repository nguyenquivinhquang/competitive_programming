#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

bool _check(char c) {
    char cond[] =  {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'} ;
    for (int i = 0; i < 11; i++) 
        if ( c == cond[i]) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        string a;
        cin >> a;
        int n = a.length() - 1;
        bool check = true;
        ll res = -1;
        for (int i = 0; i <= n; i++) {
            if (_check(a[i]) == false) continue;
            int shift = 1;
            ll len = 1;
            while (1) {
                if (i - shift < 0 || i + shift > n) break;
                if (a[i + shift] != a[i - shift] || _check(a[i+shift]) == false) break;
                len += 2;
                shift++;
            }
            res = max(res, len);
        }
        for (int i = 1; i <= n; i++) {
            if (_check(a[i]) == false | _check(a[i-1]) == false) continue;
            if (a[i] != a[i-1] ) continue;
            int shift = 1;
            ll len = 2;
            
            while (1) {
                if (i - shift - 1 < 0 || i + shift > n) break;
                if (a[i + shift] != a[i - shift - 1] || _check(a[i+shift]) == false) break;
                len += 2;
                shift++;
            }
            res = max(res, len);
        }



       cout << res << "\n";
    }
}
