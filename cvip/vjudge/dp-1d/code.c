#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define N 1000
void ex01()
{
    char c[N];
    int start=0, end=0, kq_s=0, kq_e=0;
    fgets(c, N, stdin);
    for (int i=0; i<=strlen(c);i++)
    {
        for (int j=i-1;j>=start;j--)
        {
            if (c[i]==c[j] || c[i]=='\0')
            {
                if (i-start>(kq_e-kq_s+1))
                {
                    kq_s=start;
                    kq_e=i-1;
                    start=i;
                    break;
                }
            }
        }
    }

    for (int i=kq_s; i<=kq_e; i++)
        printf("%c", c[i]);
}
void ex02()
{
    int arr[N], n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n;j++)
            if (arr[i]+arr[j]==k && i !=j)
            {
                printf("%d %d", i, j);
                return;
            }
    }
    printf("Khong tim thay cap i j thoa");
}
void ex03()
{
    int n, m, a[N], b[N], c[N], k=0;
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int i=0; i<m; i++)
        scanf("%d", &b[i]);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    for (; i<n; i++)
        c[k++] = a[i];
    for (; j<m; j++)
        c[k++] = b[j];
    float mid;
    if (k%2==0)
        mid = (c[k/2]+c[k/2-1])/2.0;
    else mid = c[k/2];
    printf("%.1f", mid);

}
int main()
{
    //ex03();
    //ex01();
    //ex02();
}