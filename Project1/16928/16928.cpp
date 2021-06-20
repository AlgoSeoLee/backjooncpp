//https://www.acmicpc.net/problem/16928

#include<iostream>
#include<queue>
using namespace std;

int nxt[102];
int d[102]; // 이동 횟수

int main() {

	for (int i = 1; i <= 100; i++) {
		nxt[i] = i;
		d[i] = -1;
	}

	int n, m; // 사다리, 뱀의 수

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) { // 구현에는 사다리든 뱀이든 둘다 이동하는거라 그냥 구별x
		int x, y;
		cin >> x >> y;
		nxt[x] = y;
	}

	d[1] = 0; // 1번칸부터 출발
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = nxt[y]; // y가 뱀이나 사다리면 또 이동해야함
			if (d[y] == -1) { // y에 방문한적 없으면
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	cout << d[100] << '\n';
}