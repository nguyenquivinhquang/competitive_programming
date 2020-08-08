#include <bits/stdc++.h>
#define maxn 505
using namespace std;
struct quangcute
{
    int x, y;
};
bool cmp(quangcute x, quangcute y)
{
    if (x.y == y.y)
        return false;
    return x.x < y.x;
}
int n;
vector<quangcute> a(maxn);
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
 
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].x;
        for (int j = 1; j <= n; j++)
            cin >> a[j].y;
        for (int i = 1; i <= 2; i++)
        sort(a.begin() + 1, a.begin() + n + 1, cmp);
        bool check = true;
        for (int i = 1; i < n; i++)
            if (a[i].x > a[i + 1].x)
            {   
                check = false;
                break;
            }
        if (check == false)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}