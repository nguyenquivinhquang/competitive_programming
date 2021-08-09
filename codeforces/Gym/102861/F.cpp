#include <bits/stdc++.h>
using namespace std;

vector<int> score(2);
vector<int> set_score(2);
int server = 0, finished = 0;

void add_point(int player) {
	if (finished) return;

	server = player;
	score[player]++;

	if ((score[player] >= 5 && abs(score[player] - score[1 - player]) >= 2) || score[player] == 10) {
		// player wins
		set_score[player]++;
		score[player] = 0;
		score[1 - player] = 0;

		if (set_score[player] == 2) finished = 1;
	}
}

void announce() {
	if (finished) {
		cout << set_score[0];
		if (set_score[0] == 2) cout << " (winner)";
		cout << " - ";
		cout << set_score[1];
		if (set_score[1] == 2) cout << " (winner)";
		cout <<  '\n';
	} else {
		cout << set_score[0] << ' ';
		cout << "(" << score[0];
		if (server == 0) cout << "*";
		cout << ") - ";
		cout << set_score[1] << ' ';
		cout << "(" << score[1];
		if (server == 1) cout << "*";
		cout << ")\n";
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	for (char c: s) {
		if (c == 'S') {
			add_point(server);
		} else if (c == 'R') {
			add_point(1 - server);
		} else {
			announce();
		}
	}

	return 0;
}