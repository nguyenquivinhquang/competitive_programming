#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,res=0;
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i*j==n)
            {
                cout<<i<<" "<<j<<endl;
                res++;
            }
    cout<<res;
}