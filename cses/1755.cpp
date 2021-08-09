#include <bits/stdc++.h>
#define maxn 10000
#define mod %
#define ll long long
using namespace std;

int main()
{
    //freopen("D:\\c++\\cse\\input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<ll> a(300, 0);
    string x;
    cin >> x;
    for (int i = 0; i < x.length(); i++)
        a[x[i]]++;

    int pos = -1, sl = 0;
    for (int i = 65; i <= 90; i++)
    {
        if (a[i] mod 2 != 0)
            pos = i, sl++;
    }

    if (sl > 1)
        cout << "NO SOLUTION";
    else
    {
        string res;
        char temp;
        for (int i = 65; i <= 90; i++)
        {
            ll t = a[i] / 2;
            temp = i;
            while (t > 0 && i != pos)
                cout << temp, t--;
        }
        string res2 = res;
        if (pos != -1)
        {
            temp = pos;
            while (a[pos] > 0)
                cout << temp, a[pos]--;
        }
        for (int i = 90; i >= 65; i--)
        {
            ll t = a[i] / 2;
            temp = i;
            while (t > 0 && i != pos)
                cout << temp, t--;
        }
        cout << res;
    }
}