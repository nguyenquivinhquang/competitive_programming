#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("/home/chichcpu/Documents/code/c++/cvip/dnq-1/4.in", "r", stdin);
    freopen("3.inp", "w", stdout);
    cout << 100 << endl;
    srand(time(NULL));
    int a = rand() % 50 + 1;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
            cout << rand() % 101 << " ";
        cout << endl;
    }
}