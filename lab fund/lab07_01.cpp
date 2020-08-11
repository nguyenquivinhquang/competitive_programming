#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;

void ex1(string str[], int n)
{
    string s = str[0];
    for (int j = 1; j < n; j++)
    {
        string temp = "";
        for (int i = 0; i < min(s.length(), str[j].length()); i++)
            if (s[i] == str[j][i])
                temp = temp + s[i];
            else
                break;
        s = temp;
    }
    cout << s;
}
int main()
{
    string str[4] = {"abc", "abcd", "abe", "abdr"};
    ex1(str, 4);

    return 0;
}