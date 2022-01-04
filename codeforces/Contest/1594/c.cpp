#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n; string str;
char c;
vector<int> res1,res2,res3;

int check3() {
    for (int i = 2; i <= n; i++) {
        bool check = true;
        for (int j = i; j <= n; j+=i) {
            if (str[j] != c) {
                check = false;
                break;
            }
        }
        if (check) return i;
    }
    return -1;

}
void solve() {
    cin >> n >> c >> str;
    str = '1' + str;
    bool check = true;
    for (int i = 1; i <= n; i++) {
        check &= str[i] == c;
    }
    if (check == true) {
        cout << "0\n";
        return;
    }
    
    int res = check3();
    if (res != -1) {
        cout << "1\n" << res << "\n";
        return;
    }
    cout << "2\n";
    cout << n-1 << " " << n;
    cout << "\n";
    res1.clear(); res2.clear(); res3.clear();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
