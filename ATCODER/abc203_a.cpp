#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c;
    cin >> a >> b  >>c ;
    if (a == b) cout << c;
    else if (a == c) cout << b;
    else if (b == c) cout << a;
    else cout << 0;
}
