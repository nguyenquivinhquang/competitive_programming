#include <bits/stdc++.h>
#define maxn 100
#define quangcute true
using namespace std;
char a[maxn][maxn], b[maxn][maxn];
int w, h, n, ship_a, ship_b, x, y, testcase, player1_step, player2_step, step;
bool player1()
{
    bool check = true;
    while (check == true || player1_step < player2_step)
    {
        player1_step++;
        step++;
        cin >> y >> x;
        x = h - 1 - x;
        if (b[x][y] != '#')
            check = false;
        else
            b[x][y] = '_', ship_b--, player1_step--;
        if (ship_b == 0 || step == n)
            break;
    }
    return false;
}
bool player2()
{
    bool check = true;
    while (check == true || player2_step < player1_step)
    {
        player2_step++;
        step++;
        cin >> y >> x;
        x = h - 1 - x;
        if (a[x][y] != '#')
            check = false;
        else
            a[x][y] = '_', ship_a--, player2_step--;
        if (ship_a == 0 || step == n)
            break;
    }
    return false;
}
int main()
{
    cin >> testcase;

    while (testcase--)
    {
        cin >> w >> h >> n;
        player2_step = player1_step = 1;
        step = ship_a = ship_b = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '#')
                    ship_a++;
            }
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> b[i][j];
                if (b[i][j] == '#')
                    ship_b++;
            }
        while (quangcute == true)
        {
            player1();
            if (step == n)
                break;
            player2();
            if (step == n)
                break;
            if (ship_b == 0 || ship_a == 0)
                break;
        }

        if (ship_a + ship_b == 0 || ship_b * ship_a != 0)
            cout << "draw";
        else if (ship_b == 0)
            cout << "player one wins";
        else if (ship_a == 0)
            cout << "player two wins";
        for (int i = step + 1; i <= n; i++)
            cin >> x >> y;
        cout << endl;
    }
}