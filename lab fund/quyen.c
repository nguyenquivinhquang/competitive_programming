#include <stdio.h>

int main()
{
    int n, a[100][100];
    int check1 = 1, check2 = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; i < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i < n; i++)
        if (a[i][i] != a[0][0])
            check1 = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; i < n; j++)
            if (i != j && a[i][j] != 0)
                check2 = -1;
    if (check1+check2==2)
        printf("yes"); else printf("NO");
}