#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

typedef pair <int, int> ii;
string board[8][8];

void init_board() 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j].push_back(char('a' + j));
			board[i][j].push_back(char('1' + i));
		}
	}
}

ii move_by(ii cur, string move) {
	if (move == "l") {
		cur = {cur.first, cur.second - 1};
	} else if (move == "r") {
		cur = {cur.first, cur.second + 1};
	} else if (move == "u") {
		cur = {cur.first + 1, cur.second};
	} else if (move == "d") {
		cur = {cur.first - 1, cur.second};
	} else {
		cur = {7, 6};
	}
	return cur;
}

void solve(int n)
{
	vector<string> move = {"r", "u", "l", "u", "r", "u", "l", "u", "r", "u", "l", "u", "r", "u", "l", "u"};
	vector<int> move_nm = {6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1};
	cout << "a1" << ' ';

	// Base cases: moving from a1 to f7
	int idx = 0;
	ii cur = {0, 0};
	while (true) {
		if (n == 2) {
			cout << board[7][cur.second] << " h8\n";
			return;
		}

		// move accordingly
		cur = move_by(cur, move[idx]);
		cout << board[cur.first][cur.second] << ' ';
		n--;

		// break at pivot
		if (cur == ii(6, 5)) {
			break;
		}

		// change move
		move_nm[idx]--;
		if (move_nm[idx] == 0) 
			idx++;
	}

	cout << board[6][5] << ' ';

	// Special 1
	if (n >= 2 && n <= 7) {
		move = {"l", "8g", "r"};
		move_nm = {n-2, 1, 1};
		while (true) {
			if (move_nm[idx] == 0)
				continue;
			// move accordingly
			cur = move_by(cur, move[idx]);
			cout << board[cur.first][cur.second] << ' ';
			n--;

			// break at pivot
			if (cur == ii(7, 7)) {
				break;
			}

			// change move
			move_nm[idx]--;
			if (move_nm[idx] == 0) 
				idx++;
		}
	}
	// Special 2
	else if (n == 8) {
		move = {"l", "8g", "d", "r", "u"};
		move_nm = {4, 1, 1, 1, 1};
		while (true) {
			if (move_nm[idx] == 0)
				continue;
			// move accordingly
			cur = move_by(cur, move[idx]);
			cout << board[cur.first][cur.second] << ' ';
			n--;

			// break at pivot
			if (cur == ii(7, 7)) {
				break;
			}

			// change move
			move_nm[idx]--;
			if (move_nm[idx] == 0) 
				idx++;
		}
	}
	// Special 3
	else if (n >= 9) {
		cout << '\n';
		cout << n << '\n';
		move = {"l", "8g", "d", "r", "d", "u"};
		move_nm = {5, 1, 1, 1, n-9, 1};
		while (true) {
			if (move_nm[idx] == 0)
				continue;

			// move accordingly
			cur = move_by(cur, move[idx]);
			cout << board[cur.first][cur.second] << ' ';
			n--;

			// change move
			move_nm[idx]--;
			if (move_nm[idx] == 0) 
				idx++;
			if (idx > move.size())
				break;
		}
	}

}
signed main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	init_board();

	int testcase = 1;
	//cin >> testcase;
	while (testcase--)
	{
		int n; cin >> n;
		//for (int i = 1; i <= 64; i++) 
		solve(n);
	}
	
}