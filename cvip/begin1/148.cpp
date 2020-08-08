#include <iostream>

using namespace std;
bool Hoai_Thuong(int x, int y) // tim ucln
{
    while (x != y)
    {
        if (x > y)
            x = x - y; else y = y - x;
    }
    if (x == 1)
        return true;
    else
        return false;
}

int main()
{
    for (int i=1;i<=7;i++)
        for (int j=1;j<i;j++)
        if (Hoai_Thuong(i,j)==true)
            cout<<j<<"/"<<i<<endl;
}