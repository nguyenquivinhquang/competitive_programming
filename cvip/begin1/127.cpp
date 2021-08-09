#include <iostream>

using namespace std;
int res = 0; int k=0;
int a[11];
void dq(int n, int sum)
{
    for (int i=n+1;i<=10;i++){
        if (sum+a[i]==k) res++; else
        if (sum+a[i]<k) dq(i,sum+a[i]); else break;
    }
}
int main()
{
    for (int i=1;i<=10;i++)
        cin>>a[i];
    cin>>k;
    dq(0,0);
    cout<<res;
}