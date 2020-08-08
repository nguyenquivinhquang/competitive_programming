#include <bits/stdc++.h>
#define maxn 100
#define mod %
using namespace std;
bool giang_bae(int x, int y, int z)
{
    int temp = min(x, y);
    temp = min(temp, z);
    int a[4]; a[0]=0;
    a[1] = x, a[2] = y, a[3] = z;
    sort(a, a + 4);
    //if (a[2]>a[1]+1) return false;
    if (a[3]>a[2]+a[1]+1) return false;
    return true;
}
int main()
{
    int t,z,x,y;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>x>>y>>z;
        if (giang_bae(x,y,z)==true) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    }
}