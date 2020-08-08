#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string n;
    while (getline(cin, n))
    {
        transform(n.begin(), n.end(),n.begin(), ::tolower);
        
        cout << n;
    }
}