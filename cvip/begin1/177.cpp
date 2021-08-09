#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string a[10000];
int kq[100][100];
int dig[10000];
int n = 0;
bool check(string x, int line)
{
    for (int i = 1; i <= n; i++)
    {
        if (x == a[i])
        {
            if ((kq[i][kq[i][0]] != line))
            {
                kq[i][0]++;
                kq[i][kq[i][0]] = line;
            }
            return true;
        }
    }
    return false;
}

void Hoai_Thuong(string x, int line)
{

    string temp = "";
    x.erase(x.length()-1,1);
    x = x + " ";
    for (int i = 0; i <= x.length() - 1; i++)
    {
        if (x[i] != ' ')
        {
            temp = temp + x[i];
        }
        else
        {
            if (check(temp, line) == false)
            {
                n++;
                a[n] = temp;
                kq[n][0] = 1;
                dig[n] = n;
                kq[n][1] = line;
            }
            temp = "";
        }
    }
}
void Thuong_Sort()
{
    string temp;
    int temp_dig;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp_dig = dig[i];
                dig[i] = dig[j];
                dig[j] = temp_dig;
            }
}
int main()
{
    string t;
    int i = 1;
    while (getline(cin, t))
    {
        if (t=="q") break;
        Hoai_Thuong(t, i);
        i++;
    }
    
    Thuong_Sort();
    for (int j = 2; j <= n; j++)
    {
        cout << a[j] << " ";
        int m = kq[dig[j]][0];
        for (int k = 1; k <= m; k++)
            cout << kq[dig[j]][k] << " ";
        cout<<endl;
    }
}