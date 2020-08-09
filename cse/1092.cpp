#include <bits/stdc++.h>
#define ll long long
#define mod %
using namespace std;
bool chek(int x, int y)
{
    return x > y;
}
int main()
{
    ll n;
    cin >> n;
    if (((n * (n + 1)) / 2) mod 2 == 1)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        if (n mod 4 != 0)
        {
            int a[n + 10], b[n + 10];
            int check[n + 10];
            check[0] = -1;
            for (int i = 1; i <= n / 2; i++)
                check[i] = check[i - 1] * -1;
            check[(n / 2) + 1] = 1;
            for (int i = (n / 2) + 2; i <= n; i++)
                check[i] = check[i - 1] * -1;

            int x = 0, y = 0;

            for (int i = 1; i <= n; i++)
                if (check[i] == 1)
                    a[++x] = i;
                else
                    b[++y] = i;
            sort(a + 1, a + x + 1, greater<int>());
            sort(b + 1, b + 1 + y, greater<int>());
            cout << y << endl;
            for (int i = 1; i <= y; i++)
                cout << b[i] << " ";
            cout << endl
                 << x << endl;
            for (int i = 1; i <= x; i++)
                cout << a[i] << " ";
        }
        else
        {
            int a[n + 10], b[n + 10];
            int check[n + 10];
            check[0] = -1;
            for (int i = 1; i <= n / 2; i++)
                check[i] = check[i - 1] * -1;
            check[(n / 2) + 1] = -1;
            for (int i = (n / 2) + 2; i <= n; i++)
                check[i] = check[i - 1] * -1;

            int x = 0, y = 0;

            for (int i = 1; i <= n; i++)
                if (check[i] == 1)
                    a[++x] = i;
                else
                    b[++y] = i;
            sort(a + 1, a + x + 1, greater<int>());
            sort(b + 1, b + 1 + y, greater<int>());
            cout << y << endl;
            for (int i = 1; i <= y; i++)
                cout << b[i] << " ";
            cout << endl
                 << x << endl;
            for (int i = 1; i <= x; i++)
                cout << a[i] << " ";
        }
    }
}