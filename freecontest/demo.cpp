using namespace std;
map<char, int> cond, ss;
int n;
pair<string, int> a[N];
vector<pair<string, int>> b[6];
void preprocess() {
    int count = 1;
    for (int i = 2; i <= 9; i++) {
        cond[char(i + '0')] = ++count;
    }
    cond['T'] = 10, cond['J'] = 11, cond['Q'] = 12, cond['K'] = 13, cond['A'] = 14;
    ss['s'] = 1, ss['h'] = 2, ss['d'] = 3, ss['c'] = 4;
}
bool cmp_greater(pair<string, int> &x, pair<string, int> &y) {
    string t1 = x.first, t2 = y.first;
    return cond[t1[0]] > cond[t2[0]];
}
bool cmp_smaller(pair<string, int> &x, pair<string, int> &y) {
    string t1 = x.first, t2 = y.first;
    return cond[t1[0]] < cond[t2[0]];
}
int countLis(vector<pair<string, int>> &c) {
    int res = 1;
    int dp[100000];

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (c[i].second > c[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    // if (c[1].second == 1 && c[2].second == 2 && c[3].second == 3)
    //     cout << "hihi";
    return res;
}
int main() {
    preprocess();
    int res = 1e9;
    vector<int> suit = {1, 2, 3, 4};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        b[ss[a[i].first[1]]].push_back(a[i]);
    }

    do
    {
        for (int i = 0; i <= 15; i++)
        {
            for (int j = 0; j < 4; j++)
                if (i & (1 << j))
                    sort(b[j + 1].begin(), b[j + 1].end(), cmp_greater); // 1 : des, 0: inc
                else
                    sort(b[j + 1].begin(), b[j + 1].end(), cmp_smaller);
            vector<pair<string, int>> temp;
            temp.push_back({"-1", -1});
            for (int i = 0; i < 4; i++) {
                for (auto v : b[suit[i]])
                    temp.push_back(v);
            }
            res = min(res, n - countLis(temp));
        }
    } while (next_permutation(suit.begin(), suit.end()));
    cout << res << endl;
}