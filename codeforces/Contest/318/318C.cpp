#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
long double x, y, m;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> x >> y >> m;
    if (x >= m || y >= m) {
        cout << 0;
        return 0;
    }
    if (x <= 0 && y <= 0) {
        cout << -1;
        return 0;
    }
    ll Min = min(x, y), Max = max(x, y);
    ll c = 0;
    if (Min < 0) {
        c = (-Min / Max + 0.5);
        Min = Max * c + Min;
    }
    while (Max < m) {
        c++;
        Min = Min + Max;
        if (Min > Max) swap(Min, Max);
    }
    cout << c;
}
