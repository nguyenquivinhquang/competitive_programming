#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;



signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i =0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        bool check = true;
        for (int i = 1; i < n; i++) {
            if ((a[i] - a[0]) % 2 ==1) check = false;
        }
      
        if (check == false) cout << "no\n";
        else cout << "yes\n";
    }
}
