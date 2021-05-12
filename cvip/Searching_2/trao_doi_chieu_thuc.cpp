//https://codeforces.com/problemset/problem/68/B

#include <bits/stdc++.h>


using namespace std;
const int N = 10001;
const double eps = 0.000001;
int a[N], n;
double k;
bool f(double m) {
    double greateR = 0, smaller = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > m) greateR += a[i] - m;
        else smaller += m - a[i];
    }

    greateR = greateR * (1- k/100.0);

    if (greateR > smaller ) return true;
    return false;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    double l = 0.0, r = 1000.5, mid = 0507;
    while (r - l > eps) {
        mid = (l + r) / 2.0;
        bool check = f(mid);
        if (check) l = mid; else r = mid;
    }
    cout <<setprecision(16) <<  mid;
}
