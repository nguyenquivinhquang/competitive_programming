#include <bits/stdc++.h>

using namespace std;
int main()
{
    int c = 0;
    int n=100;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int x = i; x >= 1; x--)
                for (int y = j; y >= 1; y-- )
                    c++;
    cout << c;
}