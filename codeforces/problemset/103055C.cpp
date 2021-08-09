#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
struct coor
{
   int x, y, z;
   double distance(coor b) {
       return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2) + pow(z - b.z, 2 ));
   }
};

double check(map<double, int> a) {
    vector<int> x;
    for (auto v : a) x.push_back(v.second);
    sort(x.begin(), x.end());
    return (x[0] == 4 && x[1] == 12 && x[2] == 12);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase--) {
        vector<coor> a(8);
        map<double, int> trace;
        for (int i = 0; i < 8; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
        }
        for (int i = 0; i < 8; i++) 
            for (int j = i + 1; j < 8; j++) {
                trace[a[i].distance(a[j])]++;
            }
        if (trace.size() != 3 || !check(trace) ) cout << "No";
        else cout << "Yes";
        cout <<"\n";

    }
}
