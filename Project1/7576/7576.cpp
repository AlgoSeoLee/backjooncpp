//https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int tomato[1001][1001];
bool visited[1001][1001];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main(void) {
	cin >> M >> N;
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && tomato[nx][ny] == 0 && !visited[nx][ny]) {
				tomato[nx][ny] = tomato[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	int max = -1;
	bool allRipe = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				allRipe = false;
			}
			if (tomato[i][j] > max) {
				max = tomato[i][j];
			}
		}
	}

	if (allRipe) cout << max - 1 << endl;
	else cout << -1 << endl;

	return 0;
}