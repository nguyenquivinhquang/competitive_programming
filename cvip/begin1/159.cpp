#include <iostream>

using namespace std;
int n;
int a[100];
void Hoai_Thuong(int i, int sum)
{
    if (sum == n)
    {
        for (int j = 1; j < i; j++)
            cout << a[j] << " ";
        cout << endl;
    }
    for (int j = a[i-1]+1; j < n; j++)
        if (sum + j <= n)
        {
            a[i] = j;
            Hoai_Thuong(i + 1, sum + j);
        } else break;
}
int main()
{
    
    cin >> n;
    Hoai_Thuong(1,0);

}