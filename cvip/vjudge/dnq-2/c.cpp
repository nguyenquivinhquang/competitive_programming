#include <bits/stdc++.h>
using namespace std;

int books[10000];

int main()
{
    int n, m;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> books[i];

        sort(books, books + n);

        cin >> m;

        int i = 0, j = n - 1;
        int bI, bJ;
        while (i < j)
        {
            if (books[i] + books[j] < m)
                ++i;
            else if (books[i] + books[j] == m)
            {
                bI = i, bJ = j;
                i++, j--;
            }
            else
                j--;
        }

        cout << "Peter should buy books whose prices are " << books[bI] << " and " << books[bJ] << ".\n\n";
    }
}