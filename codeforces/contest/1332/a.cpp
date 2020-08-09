#include <bits/stdc++.h>
#define maxn 1000
#define ll long long
using namespace std;

int main()
{
    int testcase, a, b, c, d, x1, x2, y1, y2, x, y;
    cin >> testcase;
    while ( testcase--)
    {
        bool check = true;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int cn = c - d, cc = a - b;
        if ( (x - 1 < x1 && x + 1 > x2) || (y - 1 < y1 || y + 1 > y2))
            check = false;
        x += cn, y += cc;
        if ( x < x1 || x > x2 || y < y1 || y > y2)
            check = false;
        if (check == false) cout << "No" ;
        else cout << "Yes";

        cout << endl;

    }
}