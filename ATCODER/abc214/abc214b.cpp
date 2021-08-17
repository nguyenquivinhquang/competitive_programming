#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int s, t;
ll res = 0;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> s >> t;
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= s ; j++ )
            for (int k = 0; k <= s ; k++) {
                if (i + j + k <= s && i * j * k <= t) res++;
            }
    }
    cout <<res;
}
