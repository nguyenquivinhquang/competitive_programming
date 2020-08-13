#include <bits/stdc++.h>
#define maxn 300009
#define ll long long
using namespace std;

int main()
{
    string a;
    int res = 1, c = 1;
    cin >> a;
    a = a + "1";
    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == a[i - 1])
            c++;
        else
        {
            res = max(res, c);
            c = 1;
        }
    }

    cout << res;
}