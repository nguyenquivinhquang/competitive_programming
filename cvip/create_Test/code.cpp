#include <E:\\Competitive_Programming\\MyLib\\MyLib.h>

#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>
#define maxn 10000009
#define cin infile
#define cout outfile
#define int long long
using namespace std;

ofstream outfile;
ifstream infile;

mt19937 mt;
random_in_range _random;
long long random_in_range(int min_num, int max_num) {
    uniform_int_distribution<long long unsigned> distribution(min_num, max_num);
    return distribution(mt);
}
string random_string(size_t length) {
    auto randchar = []() -> char {
        const char charset[] =
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}
///////////////////////////////////////////////////////////////////////////////////////////
vector<string> user_name, words;
void generate_string() {
    for (int i = 1; i <= 10000; i++) {
        int len_name = _random.generate(2, 3);
        user_name.push_back(random_string(len_name));
    }
    for (int i = 1; i <= 100000; i++) {
        int len_word = _random.generate(1, 10);
        words.push_back(random_string(len_word));
    }
}

void _solve(int n) {
    generate_string();
    int m =  100000;
    // cout << m << "\n";
    int max_testcase, max_value;
    if (n < 2) max_testcase = 10, max_value = 10;
    else if (n < 4) max_testcase = 10, max_value = 1000;
    else if (n < 6) max_testcase = 100, max_value = 1000;
    else max_testcase = 100000, max_value = 50000;
    int c = _random.generate(99000, 50000);
    cout << max_testcase << endl;
    for (int i = 1; i <= max_testcase; i++) {
        // int mm = max_value/2;
        // if (mm == 50000) mm = 10;
        // int r1 = _random.generate(mm, max_value);
        // int r2 = _random.generate(mm, max_value);

        // cout << r1 << " " << r2 << endl;
        if (n % 3 == 0) {
            if (i % 2 == 0) cout << "100000 "; else cout << "0 ";
        } else  if (n % 4 == 0) { if (i % 2 == 0) cout << "1 "; else cout << "0 ";}
        else {
            int r1 = _random.generate(0, 1);
            cout << r1 << " ";
        }
    }
}
;
// const double pi = (2 * acos(0));
 
double read() {
	int x; cin >> x;
	return x;
}
typedef long double ld;
 
const ld pi = acos(-1);
ll a[100005];
ll num[100005];
void solve() {  
    int n;
    memset(num, 0, sizeof(num));
    cin>>n;
    ll ans=-1;int ma=-1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ++num[a[i]];
        if(a[i]>ma){
            ma=a[i];
            ans=a[i];
        }
        else if(ma==a[i]){
            ans+=a[i];
        }
    }
    if(a[1]){
        --num[a[1]];++num[a[2]+1];
        ++num[a[1]-1];
        if(a[2]+1>ma){
            ans=min(ans,a[2]+1);
        }
        else if(a[2]+1<ma){
                if(a[1]==ma&&num[a[1]])ans=min(ans,1ll*ma*num[a[1]]);
                if(a[1]==ma&&num[a[1]]==0){
                ans=min(ans,1ll*(a[1]-1)*num[a[1]-1]);
        }
         ++num[a[1]];--num[a[2]+1];
        --num[a[1]-1];
    }
 
 
    }
        if(a[n]){
        --num[a[n]];++num[a[n-1]+1];
    ++num[a[n]-1];
    if(a[n-1]+1>ma){
        ans=min(ans,a[n-1]+1);
    }
    else if(a[n-1]+1<ma){
         if(a[n]==ma&&num[a[n]])ans=min(ans,1ll*ma*num[a[n]]);
         if(a[n]==ma&&num[a[n]]==0){
            ans=min(ans,1ll*(a[n]-1)*num[a[n]-1]);
         }
    }
    ++num[a[n]];--num[a[n-1]+1];
    --num[a[n]-1];
    }
    for(int i=2;i<n;++i){
        if(a[i]){
            --num[a[i]];++num[a[i-1]+1];
        ++num[a[i]-1];
        if(a[i-1]+1>ma){
            ans=min(ans,a[i-1]+1);
        }
        else if(a[i-1]+1<ma){
            if(a[i]==ma&&num[a[i]])ans=min(ans,1ll*ma*num[a[i]]);
            if(a[i]==ma&&num[a[i]]==0){
                ans=min(ans,1ll*(a[i]-1)*num[a[i]-1]);
            }
        }
        ++num[a[i]];--num[a[i-1]+1];
        --num[a[i]-1];
        --num[a[i]];++num[a[i+1]+1];
        ++num[a[i]-1];
        if(a[i+1]+1>ma){
            ans=min(ans,a[i+1]+1);
        }
        else if(a[i+1]+1<ma){
            if(a[i]==ma&&num[a[i]])ans=min(ans,1ll*ma*num[a[i]]);
            if(a[i]==ma&&num[a[i]]==0){
                ans=min(ans,1ll*(a[i]-1)*num[a[i]-1]);
            }
        }
        ++num[a[i]];--num[a[i+1]+1];
        --num[a[i]-1];
        }
    }
    cout<<ans<<endl;
    
    
}
void generate(int testcase) {
    _solve(testcase);
}
void generate_testcase() {
    int total_testcase = 10;
    for (int testcase = 20; testcase < 30; testcase++) {
        string output = "data/input/input" + to_string(testcase) + ".txt";
        cerr << testcase << endl;
        outfile.open(output.c_str());
        generate(testcase);
        outfile.close();
    }
}
void solve_after_random_input() {
    srand(time(NULL));
    int total_testcase = 0;

    for (int testcase = 20; testcase < 30; testcase++) {
        string input = "data/input/input" + to_string(testcase) + ".txt";
        string output = "data/output/output" + to_string(testcase) + ".txt";

        infile.open(input.c_str());
        outfile.open(output.c_str());

        cerr << input << endl;
        // cerr << output << endl;

        solve();

        infile.close();
        outfile.close();
    }
}

signed main() {
    // generate_testcase();
    solve_after_random_input();
    //     mt.seed( time(nullptr) );

    // for (int i = 1; i <= 10; i++)
    //     cerr << random_in_range(1, 15) << endl;
}
