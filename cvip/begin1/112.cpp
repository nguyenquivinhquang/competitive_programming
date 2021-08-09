#include <iostream>
#include <string>
using namespace std;

int main()
{
    int h, r;
    cin >> h;
    h = 3;
    r = h;
    string mid, a;
    mid = "*";
    a = "*";
    for (int i = 2; i < r; i++)
    {
        a = a + " ";
        mid = mid + "*";
    }
    a += "*";
    mid += "*";
    cout << mid << endl;
    for (int i = 2; i < h; i++)
    {
        cout << a << endl;
    }
    cout << mid;
}