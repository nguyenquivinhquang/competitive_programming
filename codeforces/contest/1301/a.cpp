#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define input freopen("input.txt", "r", stdin);
using namespace std;

int main()
{

    int testcase;
    string a, b, c;

    cin >> testcase;
    bool check;
    while (testcase--)
    {
        check = false;
        cin >> a >> b >> c;
        for (int i = 0; i < a.length(); i++)
        {
            check = false;
            int t = c[i];
            if (t == a[i])
                check = true;
            if (t == b[i])
                check = true;
            if (check == false)
                break;
        }
        if (check == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}