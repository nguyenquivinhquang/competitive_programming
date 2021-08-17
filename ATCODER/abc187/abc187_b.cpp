#include <bits/stdc++.h>

#define ll long long
#define pp pair<double, double>

const int N = 1000;

using namespace std;
pp coor[N];
int n;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> coor[i].first >> coor[i].second;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
                if (coor[i].first == coor[j].first) continue;
                double a = (coor[i].second - coor[j].second) / (coor[i].first - coor[j].first);
                if (abs(a) <= 1) res++; 
        }
    }
    cout << res;
}
