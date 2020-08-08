#include <string>
#include <iostream>

using namespace std;

int main()
{
    int testcase, close, n, res = 0;
    string s;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> s;
        res = 0, close = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
                close--;
            else
                close++;
            if (close < 0)
            {
                res++, close = 0;
            }
        }
        cout << res << endl;
    }
}