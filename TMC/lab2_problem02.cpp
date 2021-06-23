#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
double g(double x, double y) {
    return (x * x - y) / (5.0 * y);
}
double h(double x, double y) {
    return -x * x + x + 0.75;
}
double ep(double val, double pre_val) {
    return abs(((val - pre_val) / val) * 100);
}
void Qa() {
    double x_pre, y_pre, x, y;
    x_pre = y_pre = x = y = 1.2;
    do {
        x_pre = x, y_pre = y;
        x = g(x_pre, y_pre);
        y = h(x_pre, y_pre);
        cout << x << " " << y << endl;

    } while (ep(x, x_pre) > 0.05 && ep(y, y_pre) > 0.05);
}

double u(double x, double y) {
    return y + x * x - x - 0.75;
}

double v(double x, double y) {
    return y + 5.0 * x * y - x * x;
}

double ux(double x, double y) {
    return (2.0 * x - 1);
}

double uy(double x, double y) {
    return 1.0;
}

double vx(double x, double y) {
    return (5.0 * y - 2 * x);
}

double vy(double x, double y) {
    return (1 + 5.0 * x);
}
void Qb() {
    double x, y, prex, prey;
    x = y = prex = prey = 1.2;
    do {
        prex = x, prey = y;
        x = prex - (u(prex, prey) * vy(prex, prey) - v(prex, prey) * uy(prex, prey)) / (ux(prex, prey) * vy(prex, prey) - uy(prex, prey) * vx(prex, prey));
        y = prey - (v(prex, prey) * ux(prex, prey) - u(prex, prey) * vx(prex, prex)) / (ux(prex, prey) * vy(prex, prey) - uy(prex, prey) * vx(prex, prey));
        cout << x << " " << y << endl;

    } while ((ep(x, prex) > 0.05 && ep(y, prey) > 0.05));
}
int main() {
    int testcase;
    Qa();
    Qb();
}