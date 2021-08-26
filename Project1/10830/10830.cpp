//https://www.acmicpc.net/problem/10830
//��ǥ

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long N, B;
long long A[5][5];
long long temp[5][5];
long long ans[5][5];

// ��� ����
void Matrix_multi(long long X[5][5], long long Y[5][5])
{

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0; // ��� �ʱ�ȭ
			for (int k = 0; k < N; k++) {
				temp[i][j] += (X[i][k] * Y[k][j]);
			}
			temp[i][j] %= 1000;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			X[i][j] = temp[i][j];
}

int main()
{
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		ans[i][i] = 1; // ��������� ������ķ�
	}

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			Matrix_multi(ans, A); // ������Ŀ� A��� ���ϱ�
		}
		Matrix_multi(A, A);
		B /= 2;
	}

	 // A�� B�� ���� ���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}