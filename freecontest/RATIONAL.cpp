#include <bits/stdc++.h>
#define ll long long
#define uu __int128
using namespace std;

uu gcd(uu a, uu b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void lowest(uu &den3, uu &num3) {
    uu common_factor = gcd(num3, den3);
    den3 = den3 / common_factor;
    num3 = num3 / common_factor;
}

//Function to add two fractions
void addFraction(uu num1, uu den1, uu num2,
                 uu den2, uu &num3, uu &den3) {
    den3 = gcd(den1, den2);
    den3 = (den1 * den2) / den3;
    num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);
    lowest(den3, num3);
}
void preProcess(string &a, int pos) {
    int si = a.length();
    a.insert(si - pos, "(");
    a = a + ')';
}
void solve() {
    string a;
    int t;
    int pos = 0;
    cin >> a >> t;
    preProcess(a, t);
    // cout << a << endl;
    uu tu1, tu2, tu3, mau1, mau2, mau3, total = 0, tt, mt;
    tu1 = tu2 = tu3 = mau1 = mau2 = mau3 = 0;
    while (pos < a.length() && a[pos] != '.') {
        tu1 = tu1 * 10 + a[pos] - '0';
        pos++;
    }
    mau1 = mau2 = 1;
    pos++;
    int x = 0;
    while (pos < a.length() && a[pos] != '(') {
        tu2 = tu2 * 10 + a[pos] - '0';
        pos++, total++;
    }
    pos++;
    for (int i = 1; i <= total; i++) {
        mau2 *= 10;
    }

    while (pos < a.length() && a[pos] != ')') {
        tu3 = tu3 * 10 + a[pos] - '0';
        pos++, x++;
    }
    while (x--) {
        mau3 = mau3 * 10 + 9;
    }
    for (int i = 1; i <= total; i++)
        mau3 = mau3 * 10;
    if (mau3 == 0)
        mau3 = 1;
    addFraction(tu1, mau1, tu2, mau2, tt, mt);
    addFraction(tu3, mau3, tt, mt, tu1, mau1);
    ll kq1 = tu1, kq2 = mau1;

    printf("%lld/%lld\n", kq1, kq2);
}

int main() {
    int testcase;
    solve();
}