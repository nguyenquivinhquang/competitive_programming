#include <iostream>
#include <string>
using namespace std;

int main()
{
    int h, r;
    cin >> h;
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
        if (i != h / 2 + 1)
        {
            cout << a << endl;
        } else cout<<mid<<endl;
    cout << mid;
}