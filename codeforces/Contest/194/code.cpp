#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
//853 857 859 863 877 881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997
using namespace std;
 int prime[30], n = 22;
void backtrack(int p) {
    for (int i = 1000; i <= 10999; i++) {
        if ((588 * i) % p == 665 && (665 * i) % p == 216 && (216 * i) % p == 113 )
            cout << i << " " << p << endl;
    }
}

signed main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    // cout << 1128 % 919;
    // // cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> prime[i];
        backtrack(prime[i]);
    }
    ll p = 919, x = 209, c= 1;
    // while (c < 100) {
    //     if (x % p ==  588) {
    //         cout << c << endl;
    //         break;
    //     }
    //     c++;
    //     x *= 209;
    //     x %= p;
    // }
    // for (int i = 1; i <= 30; i++) {
    //     x *= 209;
    //     x %= p;
    //     if (i >= 25) cout <<x << endl;
    // }
    

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/