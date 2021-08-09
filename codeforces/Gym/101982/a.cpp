#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

string a,b;
int k,res,x,y;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> k >> a >> b;
    for (int i = 0; i < a.size();i++) {
        if (a[i] == b[i]) x++;
        else y++;
    }
    // cerr << x << " " << y << endl;
    res = min(k, x);
    k -= res;
    k = max(k, 0);
    y -=k;
    res += y;
    cout << res;
}
