#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, res = 0;
signed main() {
    cin >> a >> b;
    if (a <= b ) cout << b - a;
    else {
        while (a > b) {
            if (a % 2 ==0) a /= 2;
            else a++;
            res++;
        }
        cout << res + b - a;
    }
}