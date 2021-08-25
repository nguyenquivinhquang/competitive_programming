#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1000;
struct Node {
    int pre, sum, Max, suff;
};
int n, q;
Node it[N* 4];
void update(int id, int l, int r, int val, int pos) {
    if (val < l || val > r) return;
    if (l == r) {
        it[id].Max = val;
        it[id].pre = it[id].Max = it[id].suff = it[id].sum = val;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, val, pos);
    update(id * 2 + 1, mid + 1, r, val, pos);
    it[id].sum = it[id*2].sum + it[id*2+1].sum;
    it[id].pre = max(it[id * 2].sum + it[id * 2 + 1].pre, it[id*2].pre);
    it[id].suff = max(it[id * 2 + 1].suff + it[id * 2].sum, it[id * 2+ 1].suff);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
}
