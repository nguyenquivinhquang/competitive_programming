#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void ex1(int n)
{
    string ones[10]{"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
    string teens[10]{"ten", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    string tens[10]{"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    vector<int> cut;
    while (n > 0)
    {
        cut.push_back(n % 10);
        n /= 10;
    }
    int t = cut.size() - 1;
    for (int i = t; i >= 0; i--)
    {
        if (i != 1)
        {
            cout << ones[cut[i]];
            if (i == 3)
                cout << "thousand ";
            if (i == 2)
                cout << "hundred ";
        }
        else
        {
            if (cut[i - 1] > 0)
                cout << tens[cut[i]];
            else cout << teens[cut[i]];
        }
    }
}
int main(int argc, char *argv[])
{
    int testcase = atoi(argv[1]);
    
    ex1(testcase);

    return 0;
}