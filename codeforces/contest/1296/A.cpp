#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("D:\\c++\\cvip\\codeforces\\1296\\input.txt", "r", stdin);
    //freopen("4.out", "w", stdout);

    int testcase, n, sc, sl, a;
    cin >> testcase;
    while (testcase--)
    {
        sc = 0, sl = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (a % 2 == 0)
                sc++;
            else
                sl++;
        }
        if (((sc > 0 && sl > 0) || (sl % 2 == 1 && sc == 0)))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}