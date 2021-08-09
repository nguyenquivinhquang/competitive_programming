#include <iostream>
#include <cstring>
#include <vector>

#define el '\n'

using namespace std;
long long res(int x)
{
    if (x == 1)
        return -1;
    if (x == 2)
        return -1;
    if (x == 3)
        return -1;
    if (x == 4)
        return 2020;
    if (x == 5)
        return 21200;
    if (x == 6)
        return -1;
    if (x == 7)
        return 3211000;
    if (x == 8)
        return 42101000;
    if (x == 9)
        return 521001000;
    if (x == 10)
        return 6210001000;
}
int main()
{
    int t,x;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>x;
        if (x==4) cout<<1210<<" ";
        cout<<res(x)<<el;

    }
}