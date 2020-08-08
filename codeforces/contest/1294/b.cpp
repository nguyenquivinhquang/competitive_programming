#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define mod %
#define el '\n'
using namespace std;
struct cordinate
{
    int x, y;
};
cordinate a[maxn];
bool condition(cordinate m, cordinate n)
{
    if (m.x != n.x)
        return m.x < n.x;
    return m.y < n.y;
}
void debug(int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i].x << " " << a[i].y << endl;
}
int main()
{
    int n, testcase;
    cin >> testcase;
    while (testcase--)
    {
        /* code */

        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].x >> a[i].y;
        sort(a + 1, a + n + 1, condition);
        //debug(n);
        bool check = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i].x > a[i + 1].x || a[i].y > a[i + 1].y)
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            cout << "YES" << endl;
            string res = "";
            int x0 = 0, y0 = 0;

            for (int i = 1; i <= n; i++)
            {
                int x1 = a[i].x;
                int y1 = a[i].y;
                for (int r = 0; r < x1 - x0; r++)
                {
                    cout << "R";
                }
                for (int u = 0; u < y1 - y0; u++)
                {
                    cout << "U";
                }
                x0 = x1;
                y0 = y1;
                
            }
            cout<<endl;
        }
        else
            cout << "NO" << endl;
    }
}