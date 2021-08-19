#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

list<int> a;
int n;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i  = 1;i <= n; i++) {
        a.push_back(i);
    }
    auto it = a.begin();
    int s = 1;
    while (a.size()) {
        if (it == a.end()) it = a.begin();
        if (s!=2) it++, s++;
        else {
            s = 1;
            cout << *it << " ";
            it = a.erase(it);
           
        }
    }
}
