#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k;
vector<int> a;
signed main() {
    cin >> n >> k;
    a.resize(n + 10);
    int sum[4]; // sum1 = a1 + a2, sum2 = a2 + a3, sum3 = a3 + a1;
    for (int i = 1; i <= 3; i++) {
        int x = i, y = i + 1; if (y == 4) y = 1;
        int _and, _or;
        cout << "and " << x << " " << y  <<endl;
        cin >> _and;
        cout << "or " << x << " " << y  <<endl;
        cin >> _or;
        sum[i] = _and + _or;
    }
    a[1] = (sum[3] + (sum[1] - sum[2])) / 2;
    a[2] = sum[1] - a[1]; a[3] = sum[3] - a[1];
//    for (int i = 1; i <= 3; i++) cout << a[i] << " ";
    for (int i = 3; i < n; i++) {
        int x = i, y = i + 1;
        int _and, _or;
        cout << "and " << x << " " << y  <<endl;
        cin >> _and;
        cout << "or " << x << " " << y  <<endl;
        cin >> _or;
        a[i + 1] =  _and + _or - a[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    cout << "finish " << a[k] << endl;
}
