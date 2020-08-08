//Calculator with recovery response
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000001
using namespace std;

int main()
{
    int dp[maxn], n, trace[maxn];
    deque<int> answer;
    int step;
    cin >> n;
    dp[1] = dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1], trace[i] = 1;
        if (i % 2 == 0 && dp[i] > dp[i / 2])
        {
            dp[i] = dp[i / 2];
            trace[i] = 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3])
        {
            dp[i] = dp[i / 3];
            trace[i] = 3;
        }
        dp[i]++;
    }
    int pos = n;
    while (pos != 1)
    {
        answer.push_front(trace[pos]);
        if (trace[pos] == 1)
            pos--;
        else
            pos /= trace[pos];
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];
}