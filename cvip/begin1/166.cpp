#include <iostream>
#include <string.h>
using namespace std;
long long int a[101];
long long int cs[101];
long long int res[101];
int n,m=1;
void Hoai_Thuong(int x)
{
    long long int temp[101];
    for (int i=1;i<=m;i++)
        temp[i]=res[i]*x+res[i-1];
    
    for (int i=1;i<=m;i++)
        res[i]=temp[i];
    m++;
    res[m]=1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    memset(res, 0, n + 1);
    res[0]=0;
    m=2;
    res[1]=-a[1];
    res[2]=1;
    for (int i=2;i<=n;i++)
    Hoai_Thuong(-a[i]);
    for (int i=1;i<=m;i++)
        cout<<res[i]<<'\n';
    
}