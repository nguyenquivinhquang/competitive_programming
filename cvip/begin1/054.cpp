#include <iostream>

using namespace std;

bool check(int x)
{
    int sum = 0;
    for (int i = 1; i < x; i++)
        if (x % i == 0)
            sum += i;
    if (sum == x)
        return true;
    else
        return false;
}

int main()
{
    int n;
    int a[6]; a[0]=0;
    a[1] = 6;
    a[2] = 28;
    a[3] = 496;
    a[4] = 8128;
    a[5]=10000000;
    int count = 0;
    cin >> n;

    while (a[count] < n)
    {
        count++;
    };
    count--;
    cout << count << endl;
    for (int i = 1; i <= count; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}