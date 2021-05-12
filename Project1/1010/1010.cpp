//https://www.acmicpc.net/problem/1010
//¹ßÇ¥

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int arr[31][31] = {0,};

	for (int i = 1; i <= 30; i++) {
		arr[1][i] = i;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			for (int k = j - 1; k >= 1; k--) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}

	int t; 
	cin >> t;
	while (t--) {
		int n, m; 
		cin >> n >> m;
		cout << arr[n][m] << endl;
	}
	return 0;
}