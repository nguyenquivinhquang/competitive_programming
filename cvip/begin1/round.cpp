#include <iostream>
#include <iomanip>   
using namespace std;
float round2(float a);
int main()
{
    cout<<round2(111.235496);
}
float round2(float a)
{
    if (((int)(a*1000000))%10 >= 5)
    {
        return ((float)((int)(a*1000000+1)))/1000000;
    }
    else
    {
        return ((float)((int)(a*1000000)))/1000000;
    }
}