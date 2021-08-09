#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string n;
    string a[100];
    int count = 1;
    while (getline(cin, n))
    {

        string temp = n;
        for (int j = temp.length() - 1; j >= 0; j--)
            cout << temp[j];
        cout << endl;
    }
}