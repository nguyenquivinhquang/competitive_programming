#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    string res;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> res;
        if (t == res)
            cout << 0;
        if (t < res)
            cout << -1;
        if (t > res) cout << 1;
        cout << endl;
    }
}