#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
int n, temp;
map<int, int> a;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a[temp]++;
    }
    vector<int> num;
    int res =0;
    for (auto v : a) {
        res += v.second / 2;
    }
    cout << res / 2;
}
