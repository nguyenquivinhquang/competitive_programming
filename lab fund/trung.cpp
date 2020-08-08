#include <bits/stdc++.h>
#define ll long long
#define N 100
#define input                    \
    cin >> n;                    \
    for (int i = 1; i <= n; i++) \
        cin >> a[i];
using namespace std;
bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void q19()
{
    int n, temp;
    map<int, int> trace;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        trace[temp]++;
    }
    for (auto v : trace)
    {
        cout << v.first << " " << v.second << endl;
    }
}
void q20()
{
    int n, temp, pos = 0, nega = 0, prime = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (temp > 0)
            pos++;
        if (temp < 0)
            nega++;
        if (isPrime(temp) == 1)
            prime++;
    }
    cout << "positive " << pos << " negative " << nega << " prime " << prime << endl;
}
void q21()
{
    int n, a[N], res = 0;
    a[0] = 1e9;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++)
        if (a[i] >= a[i - 1] && a[i - 1] < a[i - 2])
            res++;
    cout << res;
}
void q22()
{
    int n, temp;
    map<int, int> trace;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        trace[temp] = 1;
    }
    cout << trace.size();
}
bool q23()
{
    int n, temp, x;
    map<int, bool> trace;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        trace[temp] = true;
    }
    cout << trace[x];
    //1 yes, 0 no;
}
void q24()
{
    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
        if (a[i] - a[i - 1] == 1 && a[i] >= 0)
        {
            cout << a[i - 1] << " " << a[i];
            return;
        }
}
void q25()
{
    int n, a[N];
    map<int, int> trace;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        trace[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && (a[i] + a[j]) % 2 == 0)
            {
                int ave = (a[i] + a[j]) / 2;
                if ((a[i] == a[j] && trace[ave] > 2) || (a[i] != a[j] && trace[ave] > 0))
                {
                    cout << a[i] << " " << a[j] << " " << ave << endl;
                    return;
                }
            }
}
void q26()
{

    int i, n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 2; i <= n; i++)
        if (a[i] >= a[i - 1])
            break;
    if (i > n)
    {
        cout << "descending-order sorted array";
        return;
    }

    for (i = 2; i <= n; i++)
        if (a[i] <= a[i - 1])
            break;
    if (i > n)
    {
        cout << "ascending-order sorted array";
        return;
    }
}
void q27()
{
    int n, temp, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        sum += isPrime(temp) ? 1 : 0;
    }
    if (sum == n)
        cout << "this is an all-prime array.";
    else
        cout << "this is not an all-prime array.";
}
void q28()
{
    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int i;
    for (i = 2; i <= n; i++)
        if (a[i] == a[i - 1])
            break;
    if (i <= n)
        cout << "this is not an array containing distinct elements.";
    else
        cout << "this is an array containing distinct elements.";
}
void q29()
{
    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int i;
    for (i = 2; i <= n; i++)
        if (a[i] * a[i - 1] > 0)
            break;
    if (i <= n)
        cout << "this is not an array containing positive-negative interleaved element.";
    else
        cout << "this is an array containing positive-negative interleaved element.";
}
void q30()
{
    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int i;
    for (i = 2; i <= n; i++)
        if ((a[i] + a[i - 1]) % 2 == 0)
            break;
    if (i <= n)
        cout << "this is not an array containing odd-even interleaved element. ";
    else
        cout << "this is an array containing odd-even interleaved element. ";
}
void q31()
{
    int n, temp, trace = 0, i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> temp;
        if (temp % 2 == 0)
        {
            if (temp < trace)
                break;
            trace = temp;
        }
    }
    if (i <= n)
        cout << "this is not an array containing ascending-order sorted positive elements ";
    else
        cout << "this is an array containing ascending-order sorted positive elements ";
}
int q32()
{

    int n, a[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n / 2; i++)
        if (a[i] != a[n - i + 1])
            return 0;
    return 1;
    //1 is palindrome, 0 is not palindrome
}
void q33()
{
    int n;
    cin >> n;
    cout << "positive array" << endl;
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << endl
         << "negattive array" << endl;
    for (int i = 1; i <= n; i++)
        cout << -i << " ";
    cout << endl
         << "prime array" << endl;
    int t = n, i = 1;
    while (t)
    {
        if (isPrime(i))
        {
            cout << i << " ";
            t--;
        }
        i++;
    }
    cout << endl
         << "square elements" << endl;
    for (int i = 2; i <= n + 1; i++)
        cout << i * i << " ";
}
void q34()
{
    int n;
    cin >> n;
    for (int i = 10; i <= n + 10; i++)
        cout << i << " ";
}
void q35()
{
    int n, a[N], b[N];
    map<int, int> trace;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        trace[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        b[i] = trace[a[i]];
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
}
int main()
{
    //q19();
    //q20();
    //q21();
    //q22();
    // /q23();
    //q24();
    //q25();
    //q26();
    //q27();
    //q28();
    //q29();
    //q30();
    //q31();
    //cout << q32();
    //q33();
    //q34();
    //q35();
}