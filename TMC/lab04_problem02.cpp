#include <bits/stdc++.h>

#define ll long long
#define pp pair<double, double>

const int N = 1000;

using namespace std;
double err(pp cur, pp prex) {
    return max((abs(cur.first - prex.first) / cur.first) * 100,
               (abs(cur.second - prex.second) / cur.second) * 100);
}
double df_dx(double x) {
    return 2 * (x - 3);
}
double df_dy(double y) {
    return 2 * (y - 2);
}
pp gradient_vector(double x, double y) {
    pp temp;
    temp.first = df_dx(x);
    temp.second = df_dy(y);
    //cout << temp.second << endl;
    return temp;
}
double find_h(double x, double y) {
    pp t = gradient_vector(x, y);
    x -= 3;
    y -= 2;
    return -(t.first * x + t.second * y) / (t.first * t.first + t.second * t.second);
}
pp update(double x, double y) {
    pp temp;
    double h = find_h(x, y);
    cout << h << endl;
    temp.first = x + df_dx(x) * h;
    temp.second = y + df_dy(y) * h;
    return temp;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    pp pre = {1, 1}, cur, check = {0, 0};
    int i = 0;
    while (i++ < 10) {
        cur = update(pre.first, pre.second);
        if (err(cur, pre) <= 1 || gradient_vector(cur.first, cur.second) == check)
            break;
        pre = cur;
    }
    cout << cur.first << " " << cur.second;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/