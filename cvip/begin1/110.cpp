#include <iostream>

using namespace std;
bool a[100][100];
int n;
void reset()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = false;
}
int main()
{
    reset();
    int h;
    cin>>h;
    a[1][h] = true;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= h*2+1; j++)
            if ((a[i - 1][j - 1] == true) || (a[i - 1][j] == true) || (a[i - 1][j+1] == true))
                a[i][j] = true;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h*2+1; j++)
            if (a[i][j] == true)
                cout << "*";
            else
                cout << " ";
        cout << endl;
    }
}