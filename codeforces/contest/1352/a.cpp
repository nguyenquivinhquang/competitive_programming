#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;
    int a[1000000];
    cin >> testcase;
    while (testcase--)
    {
        int n, temp, res = 0;
        cin >> n;
        temp = 0;
        while (n > 0)
        {
            int x = (n % 10) * pow(10, temp);
            if (x != 0)
            {
                res++;
                a[res] = x;
            }
            n /= 10;
            temp++;
        }
        cout << res << endl;
        for (int i = 1; i <= res; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}