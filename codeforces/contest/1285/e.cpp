#include <bits/stdc++.h>

#define el '\n'
#define mod &
#define ll long long
#define maxn 100
using namespace std;


struct  data
{
    ll l,r;
};
int n;
data a[maxn];
//////////////////////////////////////////////
bool condition(data x,data y)
{
    if (x.l<y.l) return true;
    if (x.l>y.l) return false;
    if (x.r>x.r) return false; else return true;
}
void debug()
{
    for (int i=1;i<=n;i++)
        cout<<a[i].l<<" "<<a[i].r<<el;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a,a+n+1,condition);
    debug();
}