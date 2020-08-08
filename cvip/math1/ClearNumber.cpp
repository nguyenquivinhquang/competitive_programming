#include <iostream>
#include <math.h>
using namespace std;

bool trace[100];

void pre()
{   

    trace[1] = true;
    trace[2] = false;
    trace[3] = false;
    trace[4] = false;
    trace[5] = false;
    trace[6] = false;
    trace[7] = true;
    trace[8] = false;
    trace[9] = false;
    trace[10] = true;
    trace[11] = false;
    trace[12] = false;
    trace[13] = true;
    trace[14] = false;
    trace[15] = false;
    trace[16] = false;
    trace[17] = false;
    trace[18] = false;
    trace[19] = true;
    trace[20] = false;
    trace[21] = false;
    trace[22] = false;
    trace[23] = true;
    trace[24] = false;
    trace[25] = false;
    trace[26] = false;
    trace[27] = false;
    trace[28] = true;
    trace[29] = false;
    trace[30] = false;
    trace[31] = true;
    trace[32] = true;
    trace[33] = false;
    trace[34] = false;
    trace[35] = false;
    trace[36] = false;
    trace[37] = false;
    trace[38] = false;
    trace[39] = false;
    trace[40] = false;
    trace[41] = false;
    trace[42] = false;
    trace[43] = false;
    trace[44] = true;
    trace[45] = false;
    trace[46] = false;
    trace[47] = false;
    trace[48] = false;
    trace[49] = true;
    trace[50] = false;
    trace[51] = false;
    trace[52] = false;
    trace[53] = false;
    trace[54] = false;
    trace[55] = false;
    trace[56] = false;
    trace[57] = false;
    trace[58] = false;
    trace[59] = false;
    trace[60] = false;
    trace[61] = false;
    trace[62] = false;
    trace[63] = false;
    trace[64] = false;
    trace[65] = false;
    trace[66] = false;
    trace[67] = false;
    trace[68] = true;
    trace[69] = false;
    trace[70] = true;
    trace[71] = false;
    trace[72] = false;
    trace[73] = false;
    trace[74] = false;
    trace[75] = false;
    trace[76] = false;
    trace[77] = false;
    trace[78] = false;
    trace[79] = true;
    trace[80] = false;
    trace[81] = false;
    trace[82] = true;
    trace[83] = false;
    trace[84] = false;
    trace[85] = false;
    trace[86] = true;
    trace[87] = false;
    trace[88] = false;
    trace[89] = false;
    trace[90] = false;
    trace[91] = true;
    trace[92] = false;
    trace[93] = false;
    trace[94] = true;
    trace[95] = false;
    trace[96] = false;
    trace[97] = true;
    trace[98] = false;
    trace[99] = false;
}
bool check(int a)
{
    int temp;
    while (a >= 100)
    {
        temp = 0;
        while (a > 0)
        {
            temp += pow(a % 10, 2);
            a = a / 10;
        }
        a = temp;
    }
    return trace[a];
}
int main()
{
    pre();
    int a, b, res;
    res = 0;
    check(9999);
    cin >> a >> b;

    for (int i = a; i <= b; i++)
        if (check(i) == true)
            res++;
    cout <<res<<endl;
    return 0;
}