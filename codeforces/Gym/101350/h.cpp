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
        for (int i = 0; i <= n/2; i++) {
            if (_check(a[i]) == false) check = false;
            if (a[i] != a[n -i]) check = false;
        }
        if (check == true) cout << "yes\n"; else cout << "no\n";
    }
}
