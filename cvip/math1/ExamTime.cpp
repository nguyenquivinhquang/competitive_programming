#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll snt[1000005];

int main()
{
    for (int i = 2; i <= 1e6; i++)
        snt[i] = i;
    for (int i = 2; i <= 1e6; i++)
        if (snt[i] == i)
            for (int j = 2; j < 1e6 / i; j++)
                snt[i * j] = i;
}