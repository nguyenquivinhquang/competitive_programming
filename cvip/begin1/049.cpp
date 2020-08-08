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

    memset(mark, true, 1000000);
    eratos();
    mark[1] = false;
    int t, n;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cin>>n;
        for (int i = 1; i <= n; i++)
            if ((n % i == 0) && (mark[i] == true))
            {
                cout << i << " ";
            }
        cout<<endl;
    }
    return 0;
}