#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1200000;

using namespace std;
int a[N];
bool check(vector<int> &v) {
    if (v.size() < 2) return false;
    if (v.size() > 4) return true;
    for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++) {
            for(int k=j+1;k<v.size();k++) {
                int d1,d2,d3;
                d3=k-i+abs(v[k]-v[i]);
                d1=j-i+abs(v[j]-v[i]);
                d2=k-j+abs(v[k]-v[j]);
                if(d1+d2==d3)
                return true;
            }
        }
    }
    return false;
}
void solve() {
    int n;
    ll res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        vector<int> q;
        for (int j = i; j >= 1; j--) {
            q.push_back(a[j]);
            if (check(q)) break;
            res++;
        }
    }

    cout << res << "\n";
};
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin  >> testcase;
    while (testcase--) solve();
}
