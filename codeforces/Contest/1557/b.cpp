#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int a[N], n, k;
void compress() {
    map<int,int> cm;
    for (int i = 1; i <= n; i++) {
        cm[a[i]] = 1;
    }
    int c = 1;
    for (auto &v : cm) {
        v.second = c++;
    }
    for (int i = 1; i <= n; i++) a[i] = cm[a[i]];
}
void solve() {
    cin >> n >> k; 
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll count = 0, cur = 0;
    compress();
    vector<int> hehe;
    a[0] = -1e12;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i-1] + 1){
            count++;
            hehe.push_back(cur); 
            cur = 1;
        }
        else cur++;
    }  
    hehe.push_back(cur);
    
    for (auto v : hehe) {
        if (count > k) break;
        if (count + v >= k) {
            cout << "Yes\n";
            return;
        }
        count += v;
    }
   
    cout << "No\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(10);
    int test; cin >>  test;
    while (test--) {
        solve();
    }

}
