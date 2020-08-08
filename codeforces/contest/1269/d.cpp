#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long  n,t,res,temp;
    res=temp=0;
    cin>>n;
    long long black=0, white=0;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        if (i%2==0)
            black+=t/2, white+=(t+1)/2;
        else
        {
            white+=t/2, black+=(t+1)/2;
        }
        
        
        
    }
    cout<<min(black,white);
}