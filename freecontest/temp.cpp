
#include <bits/stdc++.h>
using namespace std;
/*Hàm tìm số đảo ngược trong C*/
int reverse_num(int n)
{
    int reverse = 0;
    while (n > 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}
int main()
{
    int n, testcase;
    cin >> testcase;
    for (int test = 1; test <= testcase; test++) {
        cin >> n;
        if (reverse_num(n) == n) {
            cout << "co ";
        }
        else cout << "ko ";
        
        int a = n % 10; n /= 10;
        int b = n % 10; n /= 10;
        int c = n % 10; n /= 10;
        int d = n % 10; n /= 10;
        if (!(a == b || b == c || c == d || a == d || a == c || a == d || b == d)) {
            cout << "4 ";
        }
        else if (a == b && b == c && a != d) {
            cout << "3 ";
        }
        else if (a == b && b == d && a != d) {
            cout << "3 ";
        }
        else if (a == d && d == c && a != b) {
            cout << "3 ";
        }
        else if (b == d && d == c && a != b) {
            cout << "3 ";
        }
        cout << "\n";
    }

    return 0;
}