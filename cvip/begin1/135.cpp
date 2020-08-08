#include <iostream>

using namespace std;
bool check(long x)
{
    while (x > 0)
    {
        if ((x % 10 != 0) && (x % 10 != 7))
            return false;
        x = x / 10;
    }
    return true;
}
int main()
{
    int n, i = 7;  
    cin >> n; i=7;
    while ("quang"!="cute")
    {
        if ((i % n == 0) && (check(i) == true))
        {
            cout << i;
            break;
        }
        if (i%10==0) i=i+7; else i=i*10;
    }
}