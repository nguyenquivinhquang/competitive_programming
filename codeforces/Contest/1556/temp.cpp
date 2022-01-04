#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {

}
int a[8] = {0, 1,6,4,2,3,5,4};
signed main() {
    while (1) {
        string c; int x, y;
        cin >> c >> x >> y;
        if (c == "and") cout << (a[x] & a[y]) << endl;
        else if (c == "or") cout <<  (a[x] | a[y]) << endl;
    }
}
