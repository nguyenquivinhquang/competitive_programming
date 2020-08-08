#include <iostream>
#include <string>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    string res = "";
    for (int i = 1; i <= r; i++)
    {
        cout << "*";
        if (i == (r / 2 + 1))
            res = res + "*";
        else
            res = res + " ";
    }
    cout<<endl;
    for (int i = 1; i <= c - 2; i++)
    {
        cout << res << endl;
    }
    for (int i = 1; i <= r; i++)
    {
        cout << "*";
        
    }
}