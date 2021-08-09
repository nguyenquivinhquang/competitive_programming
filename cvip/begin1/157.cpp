#include <iostream>
#include <cmath>

using namespace std;
void Hoai_Thuong(int a, int b)
{
    cout << a / b << ".";
    int trai[55];
    int phai[55];
    int n = 1;
    a = a % b;
    bool check = true;
    while (1 != 0)
    {
        trai[n] = a;
        phai[n] = a / b;
        a = a % b;
        a = a * 10;
        for (int i = n - 1; i >= 1; i--)
        {
            if (trai[n] == trai[i])
                check = false;
        }
        if (check == false)
            break;
        n++;
    }
    int i;
    for (i = 2; i < n; i++)
        if (phai[i] != phai[n])
            cout << phai[i];
        else
            break;
    cout << "(";
    for (int j = i; j < n; j++)
        cout << phai[j];
    cout << ")" << endl;
}

int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (a % b == 0)
            cout << a / b << ".(0)" << endl;
        else
            Hoai_Thuong(a, b);
    }
}