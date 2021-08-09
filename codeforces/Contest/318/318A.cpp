#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
ll n ,k;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    if ( k <= (n+1) / 2) {
        cout << k * 2 - 1;
    } else {
        cout <<  (k - (n + 1) / 2) * 2;
    }
}

