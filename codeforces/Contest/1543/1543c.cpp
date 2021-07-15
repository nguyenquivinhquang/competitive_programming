#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define double long double
const int N = 1000;

using namespace std;
vector<double> trace;
double cc = 0;
int find_remain(double c, double m, double p) {
    double re = 0;
    if (c >= 0) re++;
    if (m >= 0 ) re ++;
    if (p >=0 ) re++;
    return re - 1;
}
void dfs(double c, double m, double p, double v, double sum, double deep) {
    // cerr << c << " " << m << " " << p << str << endl;
    double t = find_remain(c, m, p);
    
    if (t < 1){
        // p = min(p, 1.0);
        trace.push_back(p * sum * deep);
    
        return;
    }
    if (c > 1e-9) {
        double temp = c, _c = c, _p = p, _m = m;
        if (c > v) {
            double u = ( v) / t;
            _p += u, _m += u;
            _c -= v;
            _c = max(_c, cc);
        } else {
            

            _p += c/ t, _m += c / t;
            _c =-1000;
        }
        dfs(_c, _m, _p, v, sum * temp, deep + 1.0);
    }
    if (m > 1e-9) {
        double temp = m, _c = c, _p = p, _m = m;;
        if (m > v) {
            double u = (v) / t;
            _p += u, _c += u;
            _m -= v;
            _m = max(cc, _m);
        } else {
            _p += m/ t, _c += m / t;
            _m =-1000;
            
        }
        dfs(_c, _m, _p, v, sum * temp, deep + 1.0);
    }
    // p = min(p, 1.0); 
    trace.push_back(p * sum * deep);
    
}
void solve() {
    trace.clear();
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    dfs(c, m, p ,v ,1.0, 1.0);
    double sum = 0;
    for (auto v : trace) sum += v;
    cout << fixed << setprecision(12) <<  sum << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
