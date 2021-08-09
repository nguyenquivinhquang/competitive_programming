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
    cin >> h;
    a[1][h] = true;
    int l, r;
    l = h;
    r = h;
    for (int i = 2; i <= h; i++)
    {
        l--;
        r++;
        a[i][l]=true;
        a[i][r]=true;
    }

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j <= h * 2 + 1; j++)
            if (a[i][j] == true)
                cout << "*";
            else
                cout << " ";
        cout << endl;
    }
    for (int i=1;i<=h+h-1;i++)
        cout<<"*";
}