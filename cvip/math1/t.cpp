#include <iostream>

using namespace std;

int main() {
	long long T;
	long double N;
	cin >> T;
	while (T--) {
		long long a, b, count = 0;
		cin >> a >> b;
		N = a * b;
		for (long long i = 1; i <= 2 * N; i++) {
			if (long((-N) / (N - i) * i) == (-N) / (N - i) * i && (-N) / (N - i) * i > 0) {
				count++;
				if ((-N * i) / (N - i) != i) count++;
			}
		}
		cout << count << "\n";
	}
}