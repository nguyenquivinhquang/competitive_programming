#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n, a[N], prime[15]={0, 0 , 1, 1, 0, 1, 0, 1, 0, 0};
bool isPrime(int n) {
    if (n <= 1)
        return false;
  
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
  
void solve() {
    cin >> n; 
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
        if (prime[a[i]] == false){
            cout << 1 << "\n" << a[i] << "\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t = a[i] * 10 + a[j];
            if (isPrime(t) == false) {
                cout << 2 << "\n" << t << "\n";
                return;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) solve();
}
