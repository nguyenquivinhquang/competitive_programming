#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("test_input.txt", "w", stdout);
    cout << 200000 << endl;
    ll total = 1e8;
    for (int i = 1; i <= 100000; i++)
       cout << total++ << " ";
    for (int i = 1; i <= 100000; i++ )
        if (i % 2 == 0) cout << total++ << " "; else cout << total-- <<" ";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/