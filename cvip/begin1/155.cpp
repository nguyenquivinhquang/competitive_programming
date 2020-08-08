#include <iostream>
#include <string.h>

using namespace std;

int p[20], t[20];
bool trace[20];
int n = 1, m = 0;
bool xd=false;
bool check(int x)
{
    int temp = 0;
    for (int i = m; i >= 1; i--)
        if (p[i] > x)
            temp++;
    if (temp == t[x])
        return true;
    else
        return false;
}
void run()
{
    if (m==n) xd=true;
    if (xd==true) return;
    for (int i = 1; i <= n; i++)
        if (trace[i] == true)
        {
            m++;
            p[m] = i;
            if (check(i) == true)
            {
                trace[i]=false;
                run();
                trace[i]=true;
            }
             if (xd==true) return;
            m--;
        
        }
    
}
int main()
{
    while (cin >> t[n])
    {
        n++;
    }
    memset(trace,true,n+1);
    n--;
    run();
    for (int i=1;i<=n;i++)
        cout<<p[i]<<" ";
}
