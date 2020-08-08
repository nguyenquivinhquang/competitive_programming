#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;

vector<bool> mark(10001, true);
void primecal()
{

    mark[0] = mark[1] = false;

    for (int i = 2; i <= 10001; i++)
    {
        if (mark[i])
            for (int j = i * 2; j <= 10001; j += i)
                mark[j] = false;
    }
    mark[1]=false;
}
int main()
{
    primecal();
    int i = 0, n = 0, sl = 0;
    cin >> n;
    int res[20];
    while (pow(2, i) < n)
    {
        i++; int t=pow(2,i)-1;
        if (mark[t] == true)
        {
            sl++;
            res[sl] = t;
        }
    }
    if (res[sl]>=n) sl--;
    for (int i=sl;i>=1;i--)
        cout<<res[i]<<endl;
}