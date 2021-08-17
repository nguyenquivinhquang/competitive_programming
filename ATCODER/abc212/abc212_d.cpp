#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

multiset<int> q;
int curSum = 0, cond, x;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int query;
    cin >> query;
    while (query--) {
        
        cin >> cond;
        if (cond == 3) {
            cout << *q.begin() + curSum << "\n";
            q.erase(q.begin());
            continue;
        }
        cin >> x;
        if (cond == 2) curSum += x;
        else {
            x-= curSum;
            q.insert(x);
        }
    }
}
