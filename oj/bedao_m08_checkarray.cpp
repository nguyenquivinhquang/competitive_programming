#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
vector<int> a;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    bool check = true;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] > 1) check = false; 
    }
    if (check) cout << "YES";
    else cout << "NO";
}
