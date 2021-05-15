#include<bits/stdc++.h>
#define pp pair<double, double>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;

pp coor[N];
int n, k;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> coor[i].first >> coor[i].second;
    double total_distance = 0;
    for (int i = 1; i < n; i++) {
        double x = coor[i].first, y = coor[i].second, x0 = coor[i + 1].first, y0 = coor[i + 1].second;
        total_distance += sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    }
    total_distance *= k;
    cout << fixed << setprecision(9);
    cout << total_distance / 50.0;
}
