//https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int a[10001];
	int N, K;
	int count = 0;
	cin >> N >> K;

	//2���� 10���� 1�� ������ݴϴ�
	for (int i = 2; i <= N; i++) {
		a[i] = 1;
	}

	//2���� ����� ���� �����鼭 1�� �Ǿ������� 0���� �ٲ��ݴϴ�. �׸��� ī��Ʈ ����
	for (int i = 2; i <= N; i++) {
		for (int j = 1; i * j <= N; j++) {
			if (a[i * j] == 1) {
				a[i * j] = 0;
				count++;

				//ī��Ʈ�� K�� �������� ���� i*j �� ���
				if (count == K) {
					cout << i * j << endl;
					return 0;
				}

			}
		}

	}

}