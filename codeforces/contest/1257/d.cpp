#include <bits/stdc++.h>
#define maxn 200001
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;
struct hr
{
    int power, endu, max_of_endurance;
};
bool cmp(hr x, hr y)
{
    return x.power < y.power;
}

vector<int> monster(maxn);
vector<hr> hero(maxn);
int n, m, max_of_endurance[maxn], day;
void reset()
{
    day = 0;
    for (int i = 1; i <= m; i++)
        hero[i] = {0, 0, 0};
}
int main()
{
    //fastio;
    int testcase;
    m = 1000;
    cin >> testcase;
    while (testcase--)
    {
        //reset();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> monster[i];
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> hero[i].power >> hero[i].endu;
        sort(hero.begin() + 1, hero.begin() + 1 + m, cmp);
        //sort(monster.begin() + 1, monster.begin() + 1 + n);
        hero[m + 1] = {0, 0, 0};
        for (int i = m; i >= 1; i--)
        {
            hero[i].max_of_endurance = max(hero[i + 1].max_of_endurance, hero[i].endu);
        }
        int i = 0, count = 0, cm = n, max_power;
        bool check = true;
        while (i <= n)
        {
            count = 0;
            i++, count++;
            if (i > n)
                break;
            hr temp = {monster[i], 0, 0};
            auto pos = lower_bound(hero.begin() + 1, hero.begin() + 1 + m, temp, cmp);
            if (pos->power < monster[i])
            {
                continue;
            }
            cm--;
            max_power = monster[i];
            while (i < n)
            {
                i++, count++;
                max_power = max(max_power, monster[i]);
                hr temp = {max_power, 0, 0};
                pos = lower_bound(hero.begin() + 1, hero.begin() + 1 + m, temp, cmp);
                if (pos->max_of_endurance < count)
                {
                    i--;
                    break;
                }
                cm--;
            }
            day++;
        }
        if (cm != 0)
            day = -1;
        cout << day << endl;
        reset();
    }
}