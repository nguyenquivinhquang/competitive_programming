#include<bits.h/stdc++.h>


using namespace std;
double d, s ,t ;
void solve() {
    cin >> t >> s >> d; // t: impact time, s is speed, d is distance
    t *= 24;
    s *= 0.0036;
    d = abs(d);

}
signed main() {
    ios_base::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();

    }
}
