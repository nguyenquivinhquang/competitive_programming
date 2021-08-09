#include <bits/stdc++.h>
#define ll long long
#define mod %
using namespace std;
int trace[101];
int n = 0;
ll gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    int r;
    while (b > 0)
    {
        r = a mod b, a = b, b = r;
    }
    return a;
}
void pre()
{
}
int main()
{
    memset(trace, 0, sizeof(trace));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> trace[i];
    for (int i = 1; i < n; i++)
        trace[i] = abs(trace[i] - trace[i + 1]);
    int ucln = trace[1];
    for (int i = 2; i < n; i++)
        ucln = gcd(ucln, trace[i]);
    int res[1000], count_res = 0;
    for (int i = 2; i <= sqrt(ucln); i++)
        if (ucln mod i == 0)
        {
            count_res++,res[count_res]=i;
            count_res++,res[count_res]=ucln/i;
            if (ucln/i==i) count_res--;
        }
    sort(res,res+count_res+1);
    for (int i=1;i<=count_res;i++)
        cout<<res[i]<<" ";
    cout<< ucln;
}