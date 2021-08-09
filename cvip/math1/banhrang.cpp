#include <iostream>

using namespace std;
int n;
int a[1000];
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
void fraction(int a, int b)
{
    int x = a;
    int y = b;
    while (x != y)
    {
        if (x > y)
        {
            x = x - y;
        }
        else
        {
            y = y - x;
        };
    };
    cout<< a/x <<"/"<< b/x<<endl;
}
int main()
{
    input();
    int x=a[1];
    for (int i=2;i<=n;i++)
        fraction(x, a[i]);
    return 0;
}