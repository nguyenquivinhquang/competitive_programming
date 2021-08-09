#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define el '\n'
#define mod %
#define inf "INFINITY"

using namespace std;
struct datadt
{
    double x, y;
};

datadt a[maxn];

int n;
double res;
datadt res1, res2;
bool condition(datadt &a1, datadt &a2)
{
    if (a1.x > a2.x)
        return false;
    if (a1.x < a2.x)
        return true;
    if (a1.y > a2.y)
        return false;
    else if (a1.y < a2.y)
        return true;
    return true;
}

void input()
{
    a[0].x = a[0].y = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n + 1, condition);
    res = 100000000.0;
}
double distance(datadt &x, datadt &y)
{
    double temp = 0.0;
    temp = temp + sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));

    return temp;
}
double closet_two_ponits(int l, int r)
{
    if (l >= r)
        return 100000000;

    double d = 0.0000; // distance
    int mid = (l + r) / 2;

    closet_two_ponits(l, mid - 1);
    closet_two_ponits(mid + 1, r);

    for (int i = mid; i >= l; i--)
    {
        d = distance(a[i], a[mid]) + 0.0;
        if (d < res && i != mid)
            res = d;
        for (int j = mid; j <= r; j++)
            if (i != j)
            {
                d = distance(a[i], a[j]);
                if (d <= res)
                {
                    res = d;
                    res1 = a[i], res2 = a[j];
                }
                if (abs(a[j].x - a[i].x) > res)
                    break;
            }
    }
    return -1;
}
void output()
{
    cout << fixed << setprecision(2);
    cout << res1.x << " " << res1.y << " " << res2.x << " " << res2.y << endl;
}
int main()
{
    //cout << setprecision(2);
    while ("quang" != "trash")
    {
        cin >> n;
        if (n == 0)
            return 0;
        input();
        closet_two_ponits(1, n);
        output();
    }
}