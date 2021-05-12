//https://www.acmicpc.net/problem/1173

#include <iostream>
using namespace std;

int main() {
	int N, m, M, T, R, X = 0, time = 0;
	cin >> N >> m >> M >> T >> R;

	if (m + T > M) {
		cout << "-1";
		return 0;
	}

	X = m;
	while (1) {
		if (X + T <= M) {
			X += T;
			N--;
		}
		else {
			X -= R;
			if (X < m) X = m;
		}
		time++;
		if (N == 0) break;
	}

	cout << time;
	return 0;
}