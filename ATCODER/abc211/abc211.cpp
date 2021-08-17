#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

double a,b;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> a >> b;
    cout <<fixed << setprecision(9) <<  (a + 2 * b ) / 3;
}
