#include <iostream>
#include <sstream>
using namespace std;
string res = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
int k = 0;
int a[11];
int trace[8];
void in();
void dq(int n, int sum, string b)
{
    if (n == 0)
        n = 1;
    if (sum == k)
    {
        res = b;
        in();
        exit;
    }
    if (sum > k)
        exit;
    for (int i = n; i <= 4; i++)
    {
        if (sum + a[i] <= k)
        {
            string temp;
            ostringstream convert;
            convert << i;
            temp = convert.str();
            dq(i, sum + a[i], b + temp);
        }
    }
}
void in()
{
    for (int i = 0; i <= res.length() - 1; i++)
    {
        trace[res[i] - 48]++;
    }
    for (int i = 1; i <= 7; i++)
    {
        if (trace[i] != 0)
        {
            for (int j=1;j<=trace[i];j++)
            cout <<a[i]<<" ";
            trace[i]=0;
        }

    }
    cout<<endl;
}
int main()
{
    a[1] = 1;
    a[2] = 5;
    a[3] = 10;
    a[4] = 20;

    for (int i = 1; i <= 4; i++)
        trace[i] = 0;
    cin >> k;

    dq(0, 0, "");
}