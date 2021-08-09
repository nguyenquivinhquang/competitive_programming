#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string a, b;
    cin>>n;
    getline(cin,a);
    for (int i = 1; i <= n; i++)
    {
        getline(cin,a);
        getline(cin,b);
        if (a == b)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
}