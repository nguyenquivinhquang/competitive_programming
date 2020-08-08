#include <bits/stdc++.h>
#define maxn 500100

using namespace std;
int n;
char c[maxn];
int  a[maxn], b[maxn];
void Gb()
{
	int i;
	for (  i=1; i<=n; i++)
	{
		if (c[i]=='1')
		{ 
			a[i]=1, b[i]=0;
			break;
		}
		if (c[i]=='0') a[i] = 0, b[i] = 0;
		if (c[i]=='2') a[i] = 1, b[i] = 1;
	}
	for (i=i+1; i<=n; i++)
	{
		b[i]=c[i]-48, a[i]=0;
	}
	for ( int i=1; i<=n; i++)
		cout<< a[i];
	cout<<endl;

	for ( int i=1; i<=n; i++)
		cout<< b[i];
	cout<< endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
      	cin >> n;
      	for (int i=1; i<=n; i++)
      		cin>>c[i];
      	Gb();
    }
}