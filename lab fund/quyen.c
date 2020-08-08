#include <stdio.h>
void ex01()
{
    int n, a[30][30];
    scanf("%d", &n);
    a[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
void ex02()
{
    int n, m, a[30][30], temp;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= j; k++)
                if ((a[j][i] > a[k][i] && i % 2 == 0) || (a[j][i] < a[k][i] && i % 2 == 1))
                {
                    temp = a[j][i];
                    a[j][i] = a[k][i];
                    a[k][i] = temp;
                }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= j; k++)
                if (a[j][i] < a[k][i] && i % 2 != 0)
                {
                    temp = a[j][i];
                    a[j][i] = a[k][i];
                    a[k][i] = temp;
                }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
void ex03()
{
    int n, a[30][30], temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i][i] < a[j][j])
            {
                temp = a[i][i];
                a[i][i] = a[j][j];
                a[j][j] = temp;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i][n - i - 1] > a[j][n - j - 1])
            {
                temp = a[i][n - i - 1];
                a[i][n - i - 1] = a[j][n - j - 1];
                a[j][n - j - 1] = temp;
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
void ex05()
{
    int n, m, a[30][30], kq = 0;
    int fee[100000];
    for (int i = 0; i <= 100000; i++)
        fee[i] = 0;
    scanf("%d%d", &m, &n);
    a[0][1] = 1;
    int i = 1, j = 1;
    while (i <= m)
    {
        j = 1;
        while (j <= n)
        {
            scanf("%d", &a[i][j]);
            if (fee[a[i][j]] == 1)
                printf("nhap lai");
            else
            {
                fee[a[i][j]] = 1;
                j++;
            }
        }
        i++;
    }

    for (int i = 1; i <= m; i++)
    {
        int row = a[i][1];
        for (int j = 1; j <= n; j++)
            if (a[i][j] < row)
                row = a[i][j];
        if (row > kq)
            kq = row;
    }
    printf("%d", kq);
}

int main()
{
    //ex01();
    //ex02();
    //ex03();
    ex05();
    return 0;
}