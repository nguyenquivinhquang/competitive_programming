#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char res[100];
void ex5(string k, int depth = 0)
{
    if (depth > k.length())
    {
        for (int i = 1; i < depth; i++)
            cout << res[i];
        cout << " ";
        return;
    }
    string temp = dict[int(k[depth - 1]) - '0'];
    for (int i = 0; i < temp.length(); i++)
    {
        res[depth] = temp[i];
        ex5(k, depth + 1);
    }
}

int main(int argc, char *argv[])
{
    string k = "29";
    ex5(k, 1);
    return 0;
}