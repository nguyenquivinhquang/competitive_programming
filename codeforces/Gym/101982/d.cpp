#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;
const int Mod =  1000000009;
using namespace std;
unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
unsigned countBits(unsigned int number)
{     
      // log function in base 2
      // take only integer part
      return (int)log2(number)+1;
}
 
int k, b, bit1[129], po[129];
ll p = 1;
int get_po(int i) {
    if (i - 1 < 0) return 0;
    return po[i-1];

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> k >> b;
    // pre count bit1
    bit1[1] = 1;
    po[0] = 1, po[1] = 2;
    int len = countBits(k);
    for (int i = 2; i <= 128;i++) {
        po[i] = (po[i - 1] * 2) % Mod;
        p *= 2;
        bit1[i] = p + 2 *bit1[i-1];
        bit1[i] %= Mod;
    }
    bit1[0] = 1;
    ll res = 0;
    ll c_1 = countSetBits(k);
    for (int i = 0; i <= b; i++) {
        if (b - i - len < 0) break;
        ll t = (bit1[i] * get_po(b-i-len) +  bit1[b - i-len] * get_po(i)) % Mod;
        t = t + (((c_1 * po[b-i-len]) % Mod )  *  po[i] ) % Mod;
        res = (res + t) % Mod;
    }
    cout << res;
}
