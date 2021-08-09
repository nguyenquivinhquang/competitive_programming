#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool mark[1000000];
void eratos()
{
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (mark[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                mark[j] = false;
            }
        }
    }
}
int main()
{
    
    memset(mark,true,1000000);
    eratos();
    mark[1]=false;
    int x, y;
    int sl = 0;
    cin >> x >> y;
    for (int  i = x; i <= y; i++)
    {
        if (mark[i] == true)
            sl++;
    };
    cout << sl << endl;
    for (int i = x; i <= y; i++)
    {
        if (mark[i] == true)
            cout << i << endl;
    }
    return 0;
}