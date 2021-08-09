#include <iostream>

using namespace std;
const int maxn = 50;
int n;
bool check[maxn];
int a[maxn];
void dq(int x, int pos, long long value)
{
    if (pos != n)
    {
        for (int i = 1; i <= n; i++)
            if (check[i] == true)
            {
                check[i] = false;
                dq(i, pos + 1, value * 10 + a[i]);
                check[i] = true;
            }
    }
    else
        cout << value << endl;
}
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        check[i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        check[i]=false;
        dq(i,1,a[i]);
        check[i]=true;
    }
}