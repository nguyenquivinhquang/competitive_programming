#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    long double r, s1, s2, f1, f2;
    cin >> r >> s1 >> s2 >> f1 >> f2;
    long double distance = sqrt(pow(s2 - f2, 2.0) + pow(s1 - f1, 2.0));
    double prestep = (distance / (r + r)) ;
    ll step = ceilf(prestep);
    if (step == 1 && step != prestep) step++;
    cout << step;

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/