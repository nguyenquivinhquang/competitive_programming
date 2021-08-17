#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int get_sum(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

signed main() {
    ios_base:: sync_with_stdio(false), cin.tie(NULL);
    int a, b, res = 0;
    cin >> a >> b;
    res = max(get_sum(a), get_sum(b));
    cout << res;
}
