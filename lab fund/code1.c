/*
1. Input a maximum 4-digit integer n. Write a program to read the number n.
 ________________________________________________
| Input: 1234                                    |
| Output: "one thousand two hundred thirty four" |
|________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ex1(int testcase)
{
    char *ones[10] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};

    char *tens[10] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    int t[5], n = 0;
    while (testcase > 0)
    {
        t[n++] = testcase % 10;
        testcase = testcase / 10;
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (i != 1)
        {
            printf("%s", ones[t[i]]);
            if (i == 3)
                printf("thousand ");
            if (i == 2)
                printf("hundred ");
        }
        else
        {
            printf("%s", tens[t[i]]);
        }
    }
}

int main(int argc, char *argv[])
{
    int testcase = atoi(argv[1]);
    ex1(testcase);

    return 0;
}