#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int fx(int N)
{
    int r = 0;
    for (int i = 1; i <= N; i++)
    {
        if (gcd(N, i) == 1)
            r++;
    }
    return r;
}
int panda(int N)
{
    int r = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            r = r+fx(i);
    }
    return r;
}
int main()
{
    
    cout << panda(10)<<" "<<endl;
    return 1;
}