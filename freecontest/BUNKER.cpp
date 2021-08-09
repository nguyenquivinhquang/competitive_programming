#include <bits/stdc++.h>

#define ll long long
#define pp pair<double, double>
#define pi 3.14159265358979323846
const int N = 1000;

using namespace std;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    double r, x[N], y[N], alpha[N], alphaRes;
    pp a[N];
    cin >> r >> n;
    for (int i = 1; i <= n; i++) {
        cin >> alpha[i];
    }
    // sort(alpha + 1, alpha + 1 + n);
    // if (n % 2 == 0) {
    //     int p1 = n / 2, p2 = n / 2 + 1;
    //     int mid = (p1 + p2) / 2;
    //     alphaRes = alpha[mid];
    // } else {
    //     int mid = n / 2 + 1;
    //     alphaRes = alpha[mid];
    // }
    double ress = 1e9;
    for (int j = 1; j <= n; j++) {
        double res = 0;
        alphaRes = alpha[j];
        for (int i = 1; i <= n; i++) {
            double aa = abs(alphaRes - alpha[i]);
            double d = 2 * pi * r * aa / 360;
            d = min(d, 2 * pi * r - d);
            res += d;
        }
        ress = min(res, ress);
    }
    printf("%.3f", ress);
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/