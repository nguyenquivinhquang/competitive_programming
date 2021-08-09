#include <iostream>
#include <cmath>
using namespace std;
bool check(long long n)
{
    int num = 0, temp = n;
    int bac = 0;

    while (temp > 0)
    {
        bac++;
        temp = temp / 10;
    }
    temp=n;
    while (temp > 0)
    {
        num += pow(temp % 10, bac);
        temp = temp / 10;
    }
    if (num == n)
        return true;
    else
        return false;
}
int main()
{
    check(9474);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if (check(i) == true)
            cout << i << endl;
    }
}