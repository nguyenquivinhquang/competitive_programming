#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

void radixSort(int *a, int n)
{
	int i, b[N], m = a[0], exp = 1;
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)
	{
		int bucket[10] ={  0 };
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
        for (int i = 0; i < 5; i++) cout << a[i] << " ";
        cout << endl;
	}
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int arr[N] = {25, 5, 9, 10, 6};
    radixSort(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
     
}
