/*
4. Input a string and remove all blank spaces at begin and
end of the string and leave only one blank space between words.
Ex:
 ________________________________________________
| Input: "  this  is an   unformatted  string "  |
| Output: "this is an unformatted string"        |
|________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ex4(char *testcase)
{
    char a[100], words[100], temp[100];
    memset(a, 0, sizeof(a));
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < strlen(testcase); i++)
    {
        if (testcase[i] != ' ')
        {
            temp[strlen(temp)] = testcase[i];
        }
        else
        {
            int k = 0;
            for (int j = strlen(a); j < strlen(a) + strlen(temp); j++)
                a[j] = temp[k++];
            if (strlen(temp) > 0)
                a[strlen(a)] = ' ';
            memset(temp, 0, sizeof(temp));
        }
    }

    printf("%s", a);
}

int main(int argc, char *argv[])
{
    //testing variable, applying it to your algorithm for auto-evaluating
    char *testcase = "  this  is an   unformatted  string ";

    ex4(testcase);

    return 0;
}