#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
void solve()
{
    double n, p, r;
    ll res ;
    scanf("%lf%lf%lf", &n, &r, &p);
    res = ceil(log10(p / n) / log10(1.0 + r / 100.0));
    if (p<=n)
    	res=0;
    printf("%lld\n", res );
}
int main()
{
    //fastio;
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        printf("Case %d: ", i);
        solve();
    }
}