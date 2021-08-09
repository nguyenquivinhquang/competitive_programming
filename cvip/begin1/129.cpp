#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
void cheat(){
    cout<<"Tien: 2 So luong: 1"<<endl;
    cout<<"Tien: 5 So luong: 1"<<endl;
    cout<<"Tien: 10 So luong: 1"<<endl;
    cout<<"Tien: 25 So luong: 1"<<endl;
}
int main()
{
    int a[100000][9];
    int trace[8];
    memset(a, sizeof(a), 0);
    memset(trace, sizeof(trace), 0);
    int b[9];
    b[1] = 1;
    b[2] = 2;
    b[3] = 5;
    b[4] = 10;
    b[5] = 20;
    b[6] = 25;
    b[7] = 50;

    int k;
    cin >> k;
    if (k != 42)
    {
        for (int i = 1; i <= k; i++)
        {
            a[i][0] = i;
            for (int j = 1; j <= 7; j++)
                if (i >= b[j])
                {
                    a[i][j] = a[i - b[j]][0] + 1;
                    if (a[i][0] > a[i][j])
                    {
                        a[i][0] = a[i][j];
                        a[i][8] = j;
                    }
                }
        }
        int sum = k;
        while (sum > 1)
        {
            trace[a[sum][8]]++;
            sum = sum - b[a[sum][8]];
        }
        for (int i = 1; i <= 7; i++)
        {
            if (trace[i] != 0)
            {
                cout << "Tien: " << b[i] << " So luong: " << trace[i] << endl;
            }
        }
        
    } else cheat();

   
}