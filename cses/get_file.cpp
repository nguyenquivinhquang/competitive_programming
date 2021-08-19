#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int a[200001], b[200001]; 

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    for (int i = 1; i <= 200000; i++) {
        cin >> a[i];
    }
    // for (int i = 1; i <= 200000; i++){int t; cin >> t;}
    for (int i = 1; i <= 200000; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= 200000; i++) {
        if (a[i] != b[i]) cout << i << " "<< a[i] << endl;
    }
}
