#include <iostream>
#include <iomanip>
using namespace std;
bool check(double x)
{
    int i = x;
    if ((i - x) == 0.0)
        return true;
    else
        return false;
}
void Hoai_Thuong(double x)
{
    double i = 1;
    double cute = 3.3;
    while (check(cute) == false)
    {
        i++;
        cute = (2.0 * x / i) - i + 1.0;
        cute = cute / 2.0;
        if (cute < 0)
            break;
    }
    if (cute > 0)
    {
        cout << x << " = ";
        for (int j = cute; j < cute + i; j++)
        {
            if (j == cute + i - 1)
                cout << j;
            else
                cout << j << " + ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
int main()
{
    cout << fixed << setprecision(0);
    int t;
    int a;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin>>a;
        Hoai_Thuong(a);
    }
}