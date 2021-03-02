#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int n = 1000000;
using namespace std;

int cnt[1 << 16];
int dp[1 << 16];

vector<pp> buffer;

void update_all() {
    memset(dp, 0, sizeof(dp));
    for (auto p: buffer) {
        int v, a; tie(v, a) = p;
        cnt[a] += v;
    }

    for (int i = 0; i < (1 << 16); i++) {
        dp[i] = cnt[i];
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            if (j & (1 << i)) dp[j] += dp[j ^ (1 << i)];
        }
    }
    buffer.clear();
}

int answer(int S) {
    int ans = dp[S];
    for (auto p: buffer) {
        int v, a; tie(v, a) = p;

        if ((a & S) == a) ans += v;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int q, val;
    string command;
    cin >> q;
    while (q--) {
        cin >> command >> val;
        if (command[0] == 'c') cout << answer(val) << '\n';
        else {
            if (command[0] == 'd') buffer.emplace_back(-1, val);
            else buffer.emplace_back(1, val);

            if (buffer.size() == 500) update_all();
        }
    }
}
/*


8
add 1
add 3
cnt 7
del 1
cnt 5
add 6
add 2
cnt 6

*/

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
