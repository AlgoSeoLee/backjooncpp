//https://www.acmicpc.net/problem/13172

#include <iostream>
#define X 1000000007
#define ull unsigned long long

using namespace std;

ull answer, X_ = X - 2;
ull M, N, S;

ull reverse(ull N)                          // N �� ��ⷯ ������ ���� ���� ���ϱ�
{                                           // N^(X-2) ���� ��ⷯ X �� ���� ��
    ull b = 1, digit = 1, temp = N;

    while (digit <= X_)                      // X-2 ������ �����Ͽ� ����
    {
        if (digit & X_) b = (b * temp) % X;  // ��Ʈ�� 1�� �ڸ��������� b �� temp �� ������
        temp = (temp * temp) % X;           // temp �� ��� �����������ν� �� ����
        digit = digit << 1;
    }

    return b;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> N >> S;                                  // ������ ���ǿ� ����, ���м��� ������ �ʰ�
        answer = (answer + (S * reverse(N)) % X) % X;   // �� ��ⷯ������ ��ⷯ ���ϱ�� ������
    }

    cout << answer << endl;
}