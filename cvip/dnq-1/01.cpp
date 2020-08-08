#include <bits/stdc++.h>
#define maxn 10005
#define ll long long
#define el '\n'
#define mod %
#define inf "INFINITY"

using namespace std;
struct data
{
    double x, y;
};

data a[maxn];

int n;
double res;
bool condition(data &a1, data &a2)
{
    if (a1.x > a2.x)
        return false;
    if (a1.x < a2.x)
        return true;
    if (a1.y > a2.y)
        return false;
    else if (a1.y < a2.y)
        return true;
}

void input()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n + 1, condition);
    res = 100000000.0;
}
double distance(data &x, data &y)
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

    closet_two_ponits(l, mid-1);
    closet_two_ponits(mid+1, r);

    for (int i = mid; i >=l; i--)
    {
        d = distance(a[i], a[mid])+0.0;
        if (d < res && i != mid)
            res = d;
        for (int j = mid; j<=r ; j++)
        if (i!=j)
        {
            d = distance(a[i], a[j]);
            if (d <= res)
                res = d;
            if (abs(a[j].x-a[i].x)>res)
                break;
        }
    }
}
void debug()
{
    ofstream write ("debug_01.txt");
    write << "debug" << el << el;
    for (int i = 1; i <= n; i++)
    {
        write << a[i].x << " " << a[i].y << el;
    }
}
void output()
{
    cout <<fixed<< setprecision(4);
    if (res < 10000)
        cout<<res;
    else
        cout << inf;
    cout << el;
}
int main()
{
    cout << setprecision(5);
    ios::sync_with_stdio(false); cin.tie(0);

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

/*demo test

    5
    0 2
    6 67
    43 71
    39 107
    189 140

    */