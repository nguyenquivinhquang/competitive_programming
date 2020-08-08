#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream write("text.txt");
    write<<103*12<<endl;
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= 103; j++)
            write << i << " " << j << endl;
}