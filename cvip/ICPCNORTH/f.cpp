#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
bool check(int num) {
    int rev = 0, digit, n = num;
    do {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);
    if (n == rev)
        return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    for (int i = 1; i <= 2; i++) {
        int c = 0;
        for (int j = 0; j <= pow(10, i); j++)
            if (check(j))
                c++;
        cout << c << endl;
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/