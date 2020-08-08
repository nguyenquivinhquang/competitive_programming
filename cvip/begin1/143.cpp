#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

bool sochinhphuong(float n)
{

    if ((float)sqrt(n) - (int)sqrt(n) == 0)
        return true;
    return false;
}
int main()
{
    int a[50000];
    int res=1000;;
    memset(a, 0, 100);
    for (int i = 1; i <= 100; i++)
        for (int j = i; j <= 100; j++)
            for (int k = j; k <= 100; k++)
                for (int l = k; l <= 100; l++)
                {
                    //if (sochinhphuong(i * i + k * k + l * l + j * j) == true)
                    {
                        int x=(i * i + k * k + l * l + j * j);
                        a[x]++;
                        if (  a[x] >1)
                            {
                                res=min(res,x);
                                
                            }
                    }
                }

    cout<<res;
}