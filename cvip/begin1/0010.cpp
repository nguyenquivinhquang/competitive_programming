#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int x[5];
int y[5];
double edge[4];
double cal_p()
{
    double answer = 0;
    int dem = 0;
    for (int i = 2; i <= 4; i++)
    {
        dem++;
        edge[dem] = sqrt(pow(x[i] - x[i - 1], 2) + pow(y[i] - y[i - 1], 2));
    }
    if (edge[1] >= edge[2] + edge[3])
        return 0.00000;
    if (edge[2] >= edge[1] + edge[3])
        return 0.00000;
    if (edge[3] >= edge[2] + edge[1])
        return 0.00000;
    for (int i = 1; i <= 3; i++)
        answer += edge[i];
    return answer;
};
double cal_area(double p)
{
    return sqrt(p * (p - edge[1]) * (p - edge[2]) * (p - edge[3]));
}
int main()
{
    int n;
    cin >> n;
    cout << fixed;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
            cin >> x[j] >> y[j];
        x[4] = x[1];
        y[4] = y[1];
        double p = cal_p();
        if (p > 0)
            cout << setprecision(5) << cal_area(p / 2) << " "; else cout<<"0.00000 ";
        cout << setprecision(5) << p << endl;
    }
    return 0;
}