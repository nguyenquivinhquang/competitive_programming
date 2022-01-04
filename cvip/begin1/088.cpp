#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n;
int a[N], check[N];

void bruteforce(string str, int count) {
    if (count == n) {
        cout << str << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == true) {
            check[i] = false;
            bruteforce(str + to_string(a[i]), count + 1);
            check[i] = true;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        check[i] = true;
    }
    bruteforce("", 0);

}
