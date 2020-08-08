#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = rand() % 20 + 10;
    freopen("test.inp", "w", stdout);
    cout << n << " " << endl;
    for (int i = 1; i <= n; i++)
        cout << rand() % 10 + 1 << " ";
}