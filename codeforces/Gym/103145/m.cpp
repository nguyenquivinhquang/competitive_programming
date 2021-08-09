#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
map<string, string> lt;
void def() {
    
    lt["q"] = "q";
    lt["iu"] = "q";
    lt["w"] = "w";
    lt["ei"] = "w";
    lt["e"] = "e";
    lt["r"] = "r";
    lt["uan"] = "r";
    lt["t"] = "t";
    lt["ue"] = "t";
    lt["y"] = "y";
    lt["un"] = "y";
    lt["u"] = "u";
    lt["sh"] = "u";
    lt["i"] = "i";
    lt["ch"] = "i";
    lt["o"] = "o";
    lt["uo"] = "o";
    lt["p"] = "p";
    lt["ie"] = "p";
    lt["a"] = "a";
    lt["s"] = "s";
    lt["ong"] = "s";
    lt["iong"] = "s";
    lt["d"] = "d";
    lt["ai"] = "d";
    lt["f"] = "f";
    lt["en"] = "f";
    lt["g"] = "g";
    lt["eng"] = "g";
    lt["h"] = "h";
    lt["ang"] = "h";
    lt["j"] = "j";
    lt["an"] = "j";
    lt["k"] = "k";
    lt["uai"] = "k";
    lt["ing"] = "k";
    lt["l"] = "l";
    lt["uang"] = "l";
    lt["iang"] = "l";
    lt["z"] = "z";
    lt["ou"] = "z";
    lt["x"] = "x";
    lt["ia"] = "x";
    lt["ua"] = "x";
    lt["c"] = "c";
    lt["ao"] = "c";
    lt["v"] = "v";
    lt["zh"] = "v";
    lt["ui"] = "v";
    lt["b"] = "b";
    lt["in"] = "b";
    lt["n"] = "n";
    lt["iao"] = "n";
    lt["m"] = "m";
    lt["ian"] = "m";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string line;
    def();
    while (getline(cin, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word.length() == 1) cout << lt[word] << lt[word];
            else if (word.length() == 2) cout << word;
            else   if (lt.find(word) != lt.end()) cout << word[0] << lt[word];
            else {
                for (auto v : lt) for (auto u : lt) {
                    string t = v.first + u.first;
                    if (t == word) cout << v.second << u.second;
                }
            }
            cout << " ";
        }
        cout << "\n";
    }
}
