#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int solve() {
    int n;
    cin >> n;
    int count = 0, temp = n;
    while (temp > 0) {
        count++;
        temp /= 2;
    }
    count--;
    return (1 << count);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cout << solve() - 1<< "\n";
    }
}
