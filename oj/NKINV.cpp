#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i = 17, t = 0;
    while (i > 1)
    {
        i -= (i & -i), t++;
        if (t > 5)
            break;
        cout << i << endl;
    }
}