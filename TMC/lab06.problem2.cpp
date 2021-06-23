#include <bits/stdc++.h>

#define ll long long
#define pp pair<double, double>

const int N = 1000;

using namespace std;

vector<pp> data;
vector<pair<double, pp>> order, temp;
double a[N], res = 0;
int n = 0;
double X = 2.8;
double f[N];
signed main() {
    cout << setprecision(10) << fixed;
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("data2.inp", "r", stdin);
    double x, y;
    while (cin >> x >> y) {
        data.push_back({x, y});
        n++;
    }

    for (auto v : data) {
        order.push_back({v.second, {v.first, v.first}});
    }
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = X - order[i - 1].second.first;
        a[i] *= a[i - 1];
    }
    res = order[0].first;

    for (int j = 1; j < n; j++) {
        pair<double, pp> t;
        for (int i = 0; i < order.size() - 1; i++) {
            t.first = (order[i + 1].first - order[i].first) / (order[i + 1].second.second - order[i].second.first);
            t.second = {order[i].second.first, order[i + 1].second.second};
            temp.push_back(t);
        }
        order.clear();
        order = temp;
        temp.clear();
        f[j] = order[0].first;
    }

    double temp = 1.0;
    for (int i = 1; i < n; i++) {
        temp *= (X - data[i - 1].first);
        res += f[i] * temp;
    }
    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/