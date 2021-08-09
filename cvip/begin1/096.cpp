#include <iostream>
#include <string>

using namespace std;
bool check(string x)
{
    if ((x[4] == '8') || (x[4] == '7') || (x[4] == '9'))
        return true;
    return false;
}
string compare(string x, string y)
{
    int date1, date2, month1, month2, year1, year2;

    date1 = (x[0] - 48) * 10 + (x[1] - 48);
    date2 = (y[0] - 48) * 10 + (y[1] - 48);

    month1 = (x[3] - 48) * 10 + (x[4] - 48);
    month2 = (y[3] - 48) * 10 + (y[4] - 48);
    year1 = 0;
    year2 = year1;
    for (int i = 6; i < x.length(); i++)
        year1 = year1 * 10 + (x[i] - 48);
    for (int i = 6; i < y.length(); i++)
        year2 = year2 * 10 + (y[i] - 48);

    long long a, b;
    a = (year1 * 100 + month1) * 100 + date1;
    b = (year2 * 100 + month2) * 100 + date2;
    if (a > b)
        return x;
    else
        return y;
}
int main()
{
    cout << "Fall events:"<<endl;
    string res, n;
    res="1";
    while (cin >> n)
    {
        if (check(n)==true) cout<<n<<endl;
        res=compare(res,n);
    }
    cout<<"Furthest event:"<<endl;
    cout<<res;
}