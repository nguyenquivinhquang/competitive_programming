#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << a * x + b * y;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/