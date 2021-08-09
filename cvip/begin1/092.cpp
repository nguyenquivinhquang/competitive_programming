#include <iostream>
#include <string>
using namespace std;
void aa(string x)
{
    for (int i = 0; i <= x.length() - 1; i++)
        if (x[i] != ' ')
            cout << x[i];
}
int main()
{

    string n;
    int res = 0;
    string string_res;
    while (cin >> n)
    {
        if (n.length() > res)
        {
            res = n.length();
            string_res = n;
        }
    }
    cout<<string_res;
}