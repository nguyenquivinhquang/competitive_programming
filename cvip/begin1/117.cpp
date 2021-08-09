#include <iostream>

using namespace std;
long long a[51][51];
void pre(int n)
{
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            a[i][j] = 0;
}
int main()
{
    int n;
    cin >> n;
    pre(n);
    a[1][1] = 1;
    for (int i = 2; i <= n + 1; i++)
        for (int j = 1; j <= n + 1; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n + 1; j++)
            if (a[i][j] != 0)
                cout << a[i][j] << " ";
        cout<<endl;
    }
    return 0;
}