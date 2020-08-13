#include <math.h>
#include <string.h>
#include <limits.h>
#define size 1000

int ex1(char *str[], int n)
{
    int i, j, a = 0;
    char result[100];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(str[i]); j++)
        {
            if (str[i][j] == str[i++][j])
            {
                result[j] = str[i][j];
                a++;
            }
        }
    }
    printf("%s", result);
}

int main(int argc, char *argv[])
{

    char *str[] = {"abc", "abcd", "abe", "abdr"};
    ex1(str, 4);

    return 0;
}