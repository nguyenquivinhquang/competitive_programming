#include <stdio.h>

int main()
{
    int sum = 0, n;
    scanf("%d", &n);
    while (n > 0)
    {
        sum = sum + n % 10;
        n /= 10;
    }
    printf("%d", sum);
}