#include <bits/stdc++.h>
#define mod %
#define ll long long
#define maxn 200005
using namespace std;
int a[maxn];
int Giang_Bae(int p, int n)
{
    if (n==0) return 0;
    sort(a, a + n + 1);
    int count = 2;
    p = p - a[1];
    if (p < 0)
        return 0;
    int i;
    for (i = n; i >= 1; i--)
        if (p - a[i] >= 0)
        {
            
            break;
        }
    if (i == 1)
        return 1;
    
    int c=i ;  i = 2;
    while (p >= 0)
    {
        if (i==c) i++;
        count++;
        p = p - a[i];
        if ((p < 0)||(i>n))
            return count - 1;
        i++;
    }
    return count;
}
int main()
{
    int t, n, p, k, x, y;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        x = 0;
        cin >> n >> p >> k;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
           
        }
        cout << Giang_Bae(p, n) << endl;
    }
}