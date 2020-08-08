#include <stdio.h>
#include <string.h>
#define N 100
#define ll long long
#define pp pair<int, int>

int n, a[N];
int max(int x, int y)
{
    if (x < y)
        return y;
    else
        return x;
}
int q1()
{
    for (int i = 1; i <= n / 2; i++)
        if (a[i] != a[n - i + 1])
            return 0;
    return 1;
}
void q2()
{
    int temp;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < i; j++)
            if ((a[i] > a[j] && a[i] % 2 == 0 && a[j] % 2 == 0) || (a[i] < a[j] && a[i] % 2 == 1 && a[j] % 2 == 1))
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}
void q3()
{
    int inc[N], dec[N], dec_max = 0, inc_max = 0, res[N], pos = 0, temp = 1e9;
    memset(inc, 0, sizeof(inc));
    memset(dec, 0, sizeof(dec));
    inc[1] = dec[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inc[i] = dec[i] = 1;
        if (a[i] >= a[i - 1])
            inc[i] = inc[i - 1] + 1;
        if (a[i] <= a[i - 1])
            dec[i] = dec[i - 1] + 1;
        inc_max = max(inc[i], inc_max);
        dec_max = max(dec[i], dec_max);
    }
    if (inc_max > dec_max)
    {
        inc_max++;
        for (int i = n; i >= 1; i--)
            if (a[i] < temp && inc[i] == inc_max - 1)
            {
                inc_max--;
                res[pos++] = a[i];
                temp = a[i];
            }
    }
    else
    {
        temp = -1e9, dec_max++;
        for (int i = n; i >= 1; i--)
            if (a[i] > temp && dec[i] == dec_max - 1)
            {
                dec_max--;
                res[pos++] = a[i];
                temp = a[i];
            }
    }
    for (int i = pos - 1; i >= 0; i--)
        printf("%d ", res[i]);
}
int q4()
{
    int i;
    for (i = 2; i <= n; i++)
        if (a[i] >= a[i - 1])
            break;
    if (i > n)
        return -1;

    for (i = 2; i <= n; i++)
        if (a[i] <= a[i - 1])
            break;
    if (i > n)
        return 1;
    return 0;
}
void q5()
{
    int temp, i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] >= 0 && a[j] < 0)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    /*
    if (q1())
        printf("symmetric \n")
    else
       printf("not symmetric \n")
    */
    //q2();
    //q3();
    //printf("%d", q4());
    //q5();
}