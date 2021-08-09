#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int h, c, r, k;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> h >> c >> r >> k;
    if (k == 0){ cout << "NO"; exit(0);}
    if (c <= k || h + r < k)
        cout << "YES";
    else
        cout << "NO";
    // if (res & 1)
    //     cout << "YES";
    // else
    //     cout << "NO";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/