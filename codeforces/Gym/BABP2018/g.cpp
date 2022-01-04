    #include <bits/stdc++.h>

    #define ll long long
    #define pp pair<int, int>

    const int N = 300009;

    using namespace std;

    string str;

    int prefix[N][3], trace[3];
    int n, res = 1e9; 

    vector<int> a(3);
    signed main() {
        ios_base::sync_with_stdio(false), cin.tie(NULL);
        cin >> n >> str;
        for (auto c : str) trace[c - 'A']++;
        str = '$' + str + str;
        for (int i = 1; i <= n + n; i++) {
            for (int j = 0; j < 3; j++) {
                prefix[i][j] = prefix[i - 1][j] + ((str[i] - 'A') == j); 
            }
        }
        for (int i = 0 ; i < 3; i++) a[i] = i;

        do {
            int len1 = trace[a[0]], len2 = len1 + trace[a[1]], len3 = len2 + trace[a[2]];
            for (int i = 1; i  <= n; i++) {
                int s1 = prefix[i + len1 - 1][a[0]] - prefix[i - 1][a[0]];
                int s2 = prefix[i + len2 - 1][a[1]] - prefix[i + len1 - 1][a[1]];
                int s3 = prefix[i + len3 - 1][a[2]] - prefix[i + len2 - 1][a[2]];
                res = min(res, n - s1 - s2 - s3);
            }
        } while (next_permutation(a.begin(), a.end()));
        cout << res;
    }   
