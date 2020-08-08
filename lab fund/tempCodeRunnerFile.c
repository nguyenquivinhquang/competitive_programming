#include <stdio.h>
#define N 100 
void ex02()
{
    int n, a[N];
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for (int i=n; i>=1; i--)
        printf("%d ", a[i]);

}
int main()
{
    ex02();
}