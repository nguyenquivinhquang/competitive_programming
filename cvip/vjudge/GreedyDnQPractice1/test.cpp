#include <bits/stdc++.h>
#define int long long
using namespace std;
int palindrome(int n) {
    int r, sum = 0, temp;

    for (temp = n; n != 0; n = n / 10) {
        r = n % 10;
        sum = sum * 10 + r;
    }
    if (temp == sum) return 1;

    return 0;
}

signed main() {
    int a[8][8] =
                {
                        {20, -10, 11, 8, 8, 11, -10, 20},
                        {-10, -15, -4, 1, 1, -4, -15, -10},
                        {11, -4, 2, 2, 2, 2, -4, 11},
                        {8, 1, 2, -3, -3, 2, 1, 8},
                        {8, 1, 2, -3, -3, 2, 1, 8},
                        {11, -4, 2, 2, 2, 2, -4, 11},
                        {-10, -15, -4, 1, 1, -4, -15, -10},
                        {20, -10, 11, 8, 8, 11, -10, 20}
                };
    for (int i = 0 ; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}