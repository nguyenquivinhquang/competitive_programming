#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int fibo[1000];
int sum[1000];
void Hoai_Thuong()
{
    fibo[1] = fibo[2] = 1;
    sum[2] = 1;
    for (int i = 3; i <= 25; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        sum[i] = sum[i - 1] + fibo[i];
    }
}
void write(int x)
{
    for (int i = 2; i <= 25; i++)
        for (int j = 2; j <= 25; j++)
        {
            if (sum[i] - sum[j] + fibo[j] == x)
            {
                for (int k=j;k<=i;k++)
                    cout<<fibo[k]<<" ";
                cout<<endl;
                return;
            }
        }
    cout<<"no"<<endl;
}
int main()
{
    Hoai_Thuong();
    fibo[1] = 0;
    int kq[20];
    int n, a, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        write(a);
    }
}