#include <iostream>

using namespace std;

int main()
{
    
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= 9; c++)
                for (int d = 0; d <= 9; d++)
                    for (int e = 0; e <= 9; e++)
                        for (int f = 0; f <= 9; f++)
                            if (a + b + c == e + d + f)
                                cout << a << b << c << d << e << f << endl;
}