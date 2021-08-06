//https://www.acmicpc.net/problem/2467
//��ǥ

#include <iostream>
using namespace std;

const int MAX = 100000 + 1;

int N;
long long int arr[MAX];
long long int resA, resB;

int main() {

	//�Է�
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//���ʿ��� �ٰ����� index�� �ʱⰪ
	int left = 0;
	int right = N - 1;

	//������� �ʱⰪ
	int resLiquid = abs(arr[left] + arr[right]);
	resA = arr[left];
	resB = arr[right];

	//���ʿ��� �ٰ����� �ݺ�, ��� ��� Ž�� �Ϸ�� ����
	while (left < right) {
		int tmpLiquid = arr[left] + arr[right];
		if (abs(tmpLiquid) < resLiquid) {
			resLiquid = abs(tmpLiquid);
			resA = arr[left];
			resB = arr[right];
		}

		if (tmpLiquid < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	//���
	cout << resA << " " << resB << "\n";
}