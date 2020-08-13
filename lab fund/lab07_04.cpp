#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;

void ex04(string s1, string s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    vector<int> res;
    int debt = 0, x, y;
    for (int i = 0; i < max(s1.length(), s2.length()) + 1; i++)
    {
        x = y = 0;
        if (i < s1.length())
            x = s1[i] - 48;
        if (i < s2.length())
            y = s2[i] - 48;
        res.push_back(((x + y + debt) % 2));
        debt = (x + y + debt) / 2;
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << char(res[i] + 48);
}
int main(int argc, char *argv[])
{
    string n1 = "111";
    string n2 = "1111";
    ex04(n1, n2);

    return 0;
}