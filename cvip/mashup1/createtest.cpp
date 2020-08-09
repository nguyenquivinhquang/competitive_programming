#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("D:\\c++\\cvip\\mashup1\\in.txt", "w", stdout);
    srand(time(NULL));
    int n = rand() % 20 + 10;
    int l = rand() % 3 + 1;
    cout << n << " " << l << endl;
    for (int i = 1; i < n; i++)
    {
        cout << rand() % 10 << " ";
    }
}