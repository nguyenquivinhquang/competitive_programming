#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define pi  3.14159265359
const int N = 1000;

using namespace std;

double r, angle;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    
    cin >> testcase;
    while (testcase--) {
        cin >> r >>angle;
        angle *= (pi / 180.0);
        double cirle_part_area = angle * (pi * r * r) / (2 * pi);
        double rectangle_are = 0.5 * r * r * sin(angle);
        cout << fixed << setprecision(10) <<  cirle_part_area - rectangle_are << "\n";
    }
}
