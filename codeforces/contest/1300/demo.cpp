#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[100], b, c, t;
    a[2] = 880492165, a[1] = 528388, a[3] = 179952043, a[4] = 0;
    t = a[1];
    for (int i = 2; i <= 2; i++)
        t = t & (~a[i]);
    cout << t;
}