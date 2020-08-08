#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        long long int a, b, c, d;
        cin >> a >> b;
        if (a >= b)
        {
            cout << "YES" << endl;
        }
        else
        {
            if ((a == 1 and b > 1) or (a <= 3 and b > 3))
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
}