/*
4. Input 2 binary number using string then return the sum of those two.
Result should use string.
Ex:
 __________________________________________________________
| Input: 111  11                                           |
| Output: 1010                                             |
|__________________________________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define SIZE 1000

void ex4(char s1[], char s2[])
{
    char result[15];
    int a[15], b[15];
    int n = 0, m = 0, du = 0;
    for (int i = strlen(s1) - 1; i >= 0; i--)
    {
        a[n++] = s1[i] - '0';
    }
    for (int i = strlen(s2) - 1; i >= 0; i--)
    {
        b[m++] = s2[i] - '0';
    }
    int min, max;
    if (strlen(s1) < strlen(s2))
    {
        min = strlen(s1), max = strlen(s2);
    }
    else
    {
        max = strlen(s1), min = strlen(s2);
    }
    for (int i = min; i <= max; i++)
    {
        if (i >= strlen(s1))
            a[i] = 0;
        if (i >= strlen(s2))
            b[i] = 0;
    }

    for (int i = 0; i <= max; i++)
    {
        result[i] = (a[i] + b[i] + du) % 2;
        du = (a[i] + b[i] + du) / 2;
    }
    for (int i = max; i >= 0; i--)
        printf("%c", result[i] + 48);
}

int main(int argc, char *argv[])
{
    char n1[] = "111";
    char n2[] = "1111";
    ex4(n1, n2);
    char *x[10];
    x[1] = "111";

    return 0;
}