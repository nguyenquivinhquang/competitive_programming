#include <bits/stdc++.h>
#define maxn 1000001
#define ll long long
using namespace std;
int main()
{
    int n;
    //cout << "hihi";
    cin >> n;
    int a[maxn];
    if (n == 1)
        cout << "1";
    else

        if (n <= 3 && n > 1)
        cout << "NO SOLUTION";
    else
    {
        int t = n, i = 1;
        while (t > 0)
        {
            a[i++] = t;
            t -= 2;
        }
        t = n - 1;
        while (t > 0)
        {
            a[i++] = t;
            t -= 2;
        }
        if (n == 4)
            cout << "2 4 1 3 ";
        else
        {

            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
        }
    }
}