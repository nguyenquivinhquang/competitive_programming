#include <bits/stdc++.h>
#define maxn 51
using namespace std;
int trace[maxn][maxn], n, m, row[maxn], column[maxn];
void reset()
{
    memset(column, 0, sizeof(column));
    memset(row, 0, sizeof(row));
    memset(trace, 0, sizeof(trace));
}
bool find()
{
    bool cond = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (row[i] == 0 && column[j] == 0 && trace[i][j] == 0)
            {
                row[i] = 1;
                column[j] = 1;
                trace[i][j] = 1;
                return true;
            }
    return false;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        reset();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> trace[i][j];
                if (trace[i][j] == 1)
                {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        int step = 0;
        while (1 != 0)
        {
            step++;
            if (find() == false)
                break;
        }
        if (step % 2 == 0)
            cout << "Ashish";
        else
            cout << "Vivek";
        cout << endl;
    }
}