#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

list<int> a;
int n, k;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int i  = 1;i <= n; i++) {
        a.push_back(i);
    }
    // k++;
    k %= n;
    auto it = a.begin();
    int s = 0;
    while (a.size()) {
        if (it == a.end()) it = a.begin();
        if (s!=k) it++, s++;
        else {
            s = 0;
            cout << *it << " ";
            if (*it == n) {
                n--;
                it++;
            }
            it = a.erase(it);
           
        }
    }
}
