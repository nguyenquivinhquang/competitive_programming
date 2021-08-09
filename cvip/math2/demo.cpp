#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a[1000];
//int v[100][100]; // create a vector based on pointers
vector< vector<int> > vect;
void prime_factor(int x, int y)
{
    int t, count = 0;
    string res = "", temp;
    for (int i = 2; i <= x; i++)
    {
        if (x % i == 0)
        {
            t = i, count++;
            temp = to_string(i);
            
            
            res = res + temp+" ";
            while (x % i == 0)
                x = x / i;
        }
        if (x < i)
            break;
    }
    //cout << res;
    //auto it=find(a.begin(),a.end(),temp);
    a[y] = res;
}

bool cmp(string a, string b)
{
  if (a.length()<b.length())
    return true; else return false;
}
int main()
{
    ofstream write("coprime.txt");
    int count = 0;
    for (int i = 2; i <= 900; i++)
        prime_factor(i, i);
    sort(a, a + 100, cmp);
    for (int i = 2; i <= 899; i++)
        if (a[i] != a[i - 1])
            cout << a[i] << endl;
    
}