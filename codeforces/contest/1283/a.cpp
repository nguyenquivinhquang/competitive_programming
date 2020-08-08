#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cal(int h, int m)
{
    int res=0;
    res=60-m+(24-h-1)*60;
    return res;
}
int main()
{
    int t,h,m;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>h>>m;
        cout<<cal(h,m)<<endl;
    }
}