#include <iostream>
#include <string.h>
#include <math.h>
const int maxa=100;
using namespace std;

bool a[maxa];


void xl(int i)
{

    {
        int j = 1;
        int sum = i;

        while ((sum != 1) && (j <= 40))
        {
            int temp = 0;
            while ((sum >= 1))
            {
                
                temp += pow((sum % 10), 2);
                sum = sum / 10;
                j++;
            }
            sum = temp;
            //cout <<sum<<endl;
        }
        if (j >= 40)
            a[i] = false;
        else
            a[i] = true;
    }
}

int main()
{
    memset(a, false, maxa);

    for (int i = 1; i <= maxa; i++)
    {
        xl(i);
    };

    cout <<boolalpha;
    for (int i = 1; i <= 99; i++)
        cout << "trace[" <<i << "] = " << (bool)a[i]<<" ; " ;
    return 0;
}
