//https://www.acmicpc.net/problem/16928

#include<iostream>
#include<queue>
using namespace std;

int nxt[102];
int d[102]; // �̵� Ƚ��

int main() {

	for (int i = 1; i <= 100; i++) {
		nxt[i] = i;
		d[i] = -1;
	}

	int n, m; // ��ٸ�, ���� ��

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) { // �������� ��ٸ��� ���̵� �Ѵ� �̵��ϴ°Ŷ� �׳� ����x
		int x, y;
		cin >> x >> y;
		nxt[x] = y;
	}

	d[1] = 0; // 1��ĭ���� ���
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = nxt[y]; // y�� ���̳� ��ٸ��� �� �̵��ؾ���
			if (d[y] == -1) { // y�� �湮���� ������
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	cout << d[100] << '\n';
}