#include <bits/stdc++.h>
#include <Matlab
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void ex03(string n) {
    n = n + " ";
    string temp = "", res_min = "asdhujaisdhkjasdhkjasdhkjasdhkjasdhkjasdhkjasdasdasdasdasd";
    string res_max = "";
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == ' ') {
            if (temp != " ") {
                if (res_max.length() < temp.length())
                    res_max = temp;
                if (res_min.length() > temp.length())
                    res_min = temp;
            }
            temp = "";
        } else
            temp = temp + n[i];
    }
    cout << res_min << " " << res_max;
}

int main() {
    string testcase = "This is a string";
    ex03(testcase);
}