#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int prime[5000000];
int cprime = 0;
int dp[100000];
void primecal(int n)
{

    vector<bool> mark(n + 1, true);
    mark[0] = mark[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                mark[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            cprime++;
            prime[cprime] = i;
        }
    }
}
void Hoai_Thuog(long x)
{
    for (int i = 1; i <= cprime; i++)
    {
       bool check=false; 
        while (x % prime[i] == 0)
        {
            x = x / prime[i];
            check=true;
        }
        if (check==true) cout<<prime[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    primecal(5000000);
    int n,a;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a;
        Hoai_Thuog(a);
    }
    
    
}