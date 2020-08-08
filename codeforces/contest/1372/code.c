#include <stdio.h>
#define ll long int

ll q1()
{

    ll fac = 1, n;
    scanf("%lli", &n);
    for (int i = 1; i <= n; i++)
        fac *= i;
    return fac;
}
void q2()
{
    ll n;
    scanf("%lli", &n);
    for (int i = 1; i <= n; i++)
        printf("2 x %d = %lli \n", i, i * n);
}
void q3()
{
    ll n;
    scanf("%lli", &n);
    double ans;
    for (int i = 0; i <= n; i++)
        ans += 1.0 / (i * i * i);
}
void q4()
{
    ll n, sumc = 0, ;
    
    scanf("%lli", &n);
    for (int i = 0; i <= n; i++)
        printf("%d ", i);
    printf("\n");
    for (int i = n; i >= 0; i--)
        printf("%d ", i);
}
int main()
{
    q2();
}