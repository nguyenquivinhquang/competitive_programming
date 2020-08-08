#include <bits/stdc++.h>
#define maxn 101
using namespace std;
int a[maxn], n, val_min;
set <int> missing;
bool check()
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i + 1])
            return false;
        
    }
    return true;
}
int find_min()
{
    for (int i=1; i<=n; i++)
    {
        
    }
}
int main()
{
}