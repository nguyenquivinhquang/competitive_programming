#include <iostream>
#include <math.h>
using namespace std;
int sochinhphuong(float n)
{

    if ((float)sqrt(n) - (int)sqrt(n) == 0)
        return 1;
    return 0;
}
void pitago()
{
}
int main()
{
    int i, j, n;
    cin >> n;
    for (int i = n; i >= 1; i--)
        for (j = i - 1; j >= 1; j--)
        {
            if ((i*i-j*j!=0)&& (i*i-j*j<=j*j)) 
            if (sochinhphuong(i*i-j*j)){
                cout << sqrt(i * i - j * j) << " " << j << " " << i << endl;
            }
        }
}