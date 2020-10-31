// Nimionese
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 10009;

using namespace std;
vector<int> consonants = {int('b'), int('c'), int('d'), int('g'),
                          int('k'), int('n'), int('p'), int('t')};
vector<string> addon = {"ah", "oh", "uh"};
char find_S(char x) {
    bool check = true;
    if (x < 'a') {
        x = tolower(x);
        check = false;
    }

    for (auto v : consonants)
        if (x == v) {
            if (check == false)
                x = toupper(x);
            return x;
        }
    char res = consonants[0];
    for (auto v : consonants) {
        if (abs(v - x) < abs(res - x))
            res = v;
    }
    if (!check)
        res = toupper(res);
    return res;
}
string add(char x) {
    // ending = {"b": "ah", "c": "ah", "d": "ah", "g": "ah", "k": "oh", "n":
    // "oh", "p": "oh", "t": "uh"}
    if (x < 'a')
        x = tolower(x);
    if (x == 'b' || x == 'c' || x == 'd' || x == 'g')
        return "ah";
    if (x == 'k' || x == 'n' || x == 'p')
        return "oh";
    if (x == 't')
        return "uh";
    return "";
}
void proccess(string x) {
    vector<string> a;
    string temp = "";
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '-') {
            a.push_back(temp);
            temp = "";
        } else
            temp = temp + x[i];
    }
    a.push_back(temp);
    for (int i = 0; i < a.size(); i++) {
        if (i == 0)
            a[i][0] = find_S(a[i][0]);
        else {
            for (int j = 0; j < a[i].size(); j++) {
                if (find(consonants.begin(), consonants.end(), a[i][j]) !=
                    consonants.end())
                    a[i][j] = tolower(a[0][0]);
            }
        }
    }
    int i = a.size() - 1;
    int s = a[i].size() - 1;
    a[i] = a[i] + add(a[i][s]);
    for (auto v : a)
        cout << v;
    // cout << " ";
}
signed main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    string x;
    int t = 0;
    while (cin >> x) {
        if (t != 0)
            cout << " ";
        t++;
        proccess(x);
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/