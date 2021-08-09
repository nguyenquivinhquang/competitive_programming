#include <iostream>

using namespace std;
int cal(int a, int b, int c)
{
    if (c == 1)
        return a + b;
    if (c == 2)
        return a - b;
    if (c == 3)
        return a * b;
}
char dau(int a)
{
    if (a == 1)
        return '+';
    if (a == 2)
        return '-';
    if (a == 3)
        return '*';
}
int main()
{
    //cout << "((((1*2)*3)*4)+5)+6";
    int sum;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                for (int l = 1; l <= 3; l++)
                    for (int p = 1; p <= 3; p++)
                    {
                        sum = cal(1, 2, i);
                        sum = cal(sum, 3, j);
                        sum = cal(sum, 4, k);
                        sum = cal(sum, 5, l);
                        sum = cal(sum, 6, p);
                        if (sum == 35)
                        {
                            cout << "((((1" << dau(i) << "2)" << dau(j) << "3)" << dau(k) << "4)" << dau(l) << "5)" << dau(p) << "6" << endl;
                        }
                    }

    
}