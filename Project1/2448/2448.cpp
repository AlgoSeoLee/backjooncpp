#include<iostream>
using namespace std;

int N(0);
char board[3100][6200] = {};

// x가 행, y가 열
void stars(int n, int x, int y) {
	if (n == 3) {
		board[x][y + 2] = '*';
		board[x + 1][y + 1] = '*'; board[x + 1][y + 3] = '*';
		for (int i = 0; i < 5; i++) { 
			board[x + 2][y + i] = '*'; 
		}
		return;
	}
	stars(n / 2, x, y + n / 2);
	for (int i = 0; i < 3; i++) {
		if (i == 1) { 
			continue; 
		}
		stars(n / 2, x + n / 2, y + i * (n / 2));
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			board[i][j] = ' ';
		}
	}
	stars(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}