//https://www.acmicpc.net/problem/17070

#include <iostream>

using namespace std;

#define input_max 17
int n;

int a[input_max][input_max];

int dx[] = { 0, 1, 1 }; // ���� �밢�� ���� ��
int dy[] = { 1, 1, 0 }; // ���� �밢�� ���� ��
int result;

bool ok(int x, int y, int dir) {

	if (dir == 0) { //�����Ϸ��� ������ ������ �� ������ ���� üũ

		for (int k = 0; k < 1; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (!(nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)) {
				return false;
			}
		}

	}

	else if (dir == 1) { //�����Ϸ��� ������ �밢���� �� ������ ���� üũ
		for (int k = 0; k < 3; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (!(nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)) {
				return false;
			}
		}

	}

	else if (dir == 2) { //�����Ϸ��� ������ ������ �� ������ ���� üũ
		for (int k = 2; k < 3; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (!(nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)) {
				return false;
			}
		}

	}

	return true;

}

void dfs(int x, int y, int dir) {

	if (x == n && y == n) { // N x N �� �������� �� ī��Ʈ 1�߰�
		result++;
		return;
	}



	if (dir == 0) { //�������� ������ ������ ��

		for (int k = 0; k < 2; k++) {
			if (ok(x, y, k)) {
				dfs(x + dx[k], y + dy[k], k);

			}
		}

	}
	else if (dir == 1) { //�������� ������ �밢���� ��

		for (int k = 0; k < 3; k++) {
			if (ok(x, y, k)) {
				dfs(x + dx[k], y + dy[k], k);
			}
		}
	}
	else if (dir == 2) { //�������� ������ ������ ��
		for (int k = 1; k < 3; k++) {
			if (ok(x, y, k)) {
				dfs(x + dx[k], y + dy[k], k);
			}
		}
	}
}

void solution() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i + 1][j + 1];
		}
	}

	dfs(1, 2, 0); // 1, 2 ��ǥ���� ����! ������ ���� ��, dir = 0

	cout << result << '\n';

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solution();


	return 0;
}