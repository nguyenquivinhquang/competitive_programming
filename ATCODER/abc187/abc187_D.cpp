#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, sum = 0;
vector<int> a;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        sum -= x;
        a.push_back(y + x + x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int curSum = 0, id = 0;
    for (auto v : a) {
        sum += v;
        id++;
        if (sum > 0) break;
    }   
    cout << id;
}
