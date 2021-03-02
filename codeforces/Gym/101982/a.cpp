#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string a, b;
    int k, x0 = 0, x1 = 0;
    cin >> k >> a >> b;
    for (int i = 0; i < a.length(); i++)
        if (a[i] == b[i])
            x1++;
        else
            x0++;
    if (x1 >= k)
        cout << k + x0;
    else
        cout << a.length() - k + x1;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/