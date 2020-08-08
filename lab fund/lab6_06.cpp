#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
bool check(string a)
{
    stack<char> s;
    for (int i = 0; i < a.length(); i++)
    {

        if ((a[i] == ')' || a[i] == ']' || a[i] == '}') && s.size() == 0)
            return false;
        else if (a[i] == '(' || a[i] == '[' || a[i] == '{')
            s.push(a[i]);
        else if ((a[i] == ')' && s.top() == '(') ||
                 (a[i] == ']' && s.top() == '[') ||
                 (a[i] == '}' && s.top() == '{'))
            s.pop();
        else
            return false;
    }
    return s.empty();
}
void ex05(string a)
{
    if (check(a) == true)
        cout << "valid";
    else
        cout << "invalid ";
}
int main()
{
    ex05("[{()}]");
    ex05("([)]");
}
