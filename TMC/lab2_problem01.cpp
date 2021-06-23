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
double f(double x) {
    return log(pow(x, 4));
}
void Qa() {
    double xL = 0.5, xU = 2;
    double mid = (xL + xU) / 2.0;
    for (int i = 1; i <= 3; i++) {
        mid = (xL + xU) / 2.0;
        double temp = f(mid);
        if (f(xL) * temp < 0)
            xU = mid;
        else if (f(xL) * temp > 0)
            xL = mid;
        else
            break;
    }
    cout << mid << endl;
}
void Qb() {
    double xL = 0.5, xU = 2;
    double mid = (xL * f(xU) - xU * f(xL)) / (f(xU) - f(xL));
    for (int i = 1; i <= 3; i++) {
        mid = (xL * f(xU) - xU * f(xL)) / (f(xU) - f(xL));
        double temp = f(mid);

        if (temp < 0)
            xL = mid;
        else if (temp > 0)
            xU = mid;
        else
            break;
    }
    cout << mid;
}
int main() {
    int testcase;
    Qa();
    Qb();
}