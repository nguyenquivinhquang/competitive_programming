#include <iostream>

using namespace std;
bool check(long long n)
{
    long long res = n * n;
    int cs = 10, temp = n;
    while (temp > 10)
    {
        temp = temp / 10;
        cs = cs * 10;
    }
    if (res % cs == n)
        return true;
    return false;
}
int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (check(i) == true)
            cout << i << endl;
}