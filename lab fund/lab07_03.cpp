#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;

pp StringToComplex(string x)
{
    pp temp = {0, 0};
    int i = 0;
    while (x[i] != '+' && x[i] != '-')
    {
        temp.first = temp.first * 10 + int(x[i++]) - 48;
    }
    i++;
    while (x[i] != 'i')
    {
        temp.second = temp.second * 10 + int(x[i++]) - 48;
    }
    return temp;
}
string ComplexToString(pp x)
{
    string temp;
    temp = to_string(x.first);
    if (x.second >= 0)
        temp = temp + "+";

    temp = temp + to_string(x.second) + 'i';
    return temp;
}
pp product(pp x, pp y)
{
    pp temp;
    temp.first = x.first * y.first - x.second * y.second;
    temp.second = x.first * y.second + y.first * x.second;
    return temp;
};
void ex3(char s1[], char s2[])
{
    cout << ComplexToString(product(StringToComplex(s1), StringToComplex(s2)));
}

int main(int argc, char *argv[])
{
    char n1[] = "1+9i";
    char n2[] = "8+7i";
    ex3(n1, n2);

    return 0;
}