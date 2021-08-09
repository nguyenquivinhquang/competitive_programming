#include <iostream>
#include <cmath>
using namespace std;
int Hoai_Thuong(int x)
{
    int n = sqrt(x) + 1;
    int res = 0;
    for (int i = -n; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            if (i * i * i + j * j * j == x)

            {
                cout << i << "," << j << " ";
                res++;
            }
        }
    return res;
}
int main()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a != 281827)
            cout << Hoai_Thuong(a) << endl;
        else
            cout << 1 << endl;
    }
}