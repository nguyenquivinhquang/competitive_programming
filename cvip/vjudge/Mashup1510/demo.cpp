#include <bits/stdc++.h>
#define N 100
#define Quyen "Cute"
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
void solve() {}
int main() {
    freopen("/mnt/CODE/cp1/cvip/vjudge/Mashup1510/input.txt", "r", stdin);
    double n, a[N];
    double sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // cout << a[i] <<" ";
        sum += a[i];
        a[i] *= 100;
    }
    map<int, int> pre;
    double ss = 2660;
    for (int i = 1; i <= 12; i++) {
        pre[ss] = 0;
        ss += 50;
    }
    int trace[N];
    reset(trace,0);
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (auto v : pre) {
            c++;
            if (a[i] >= v.first && a[i] < (v.first + 50)) trace[c]++;
        }
    }
    int c = 0;
    for (auto v : pre) {c++;
        cout << v.first << ": " << trace[c] << endl;
    }
}
