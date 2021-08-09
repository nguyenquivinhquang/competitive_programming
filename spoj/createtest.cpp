#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 5;
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    cout << "6 5" << endl;
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << rand() % 2 << " ";
        cout << endl;
    }
}