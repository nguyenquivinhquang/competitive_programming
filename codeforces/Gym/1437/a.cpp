#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 10009;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    long long l, r;
    while(testcase -- ) {
        cin >> l >> r;
        if (2 * l > r)
            cout << "YES\n"; else cout <<"NO\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/