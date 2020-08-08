#include <iostream>
#include <string.h>

using namespace std;
bool check[100];
int a[100];
int b[100];
int n = 1;

void dq(int x)
{
    if (x == n)
    {
        for (int i = 1; i <= n; i++)
            cout << a[b[i]] << " ";
        cout << endl;
        exit;
    }
    for (int i = 1; i <= n; i++)
        if (check[i] == false)
        {
            check[i] = true;
            b[x+1]=i;
            dq(x + 1);
            check[i] = false;
        }
}
int main()
{
    memset(check, false, 100);
    
    
    while (cin >> a[n])
    {
        n++;
    }
    n--;
    dq(0);
}