//https://www.acmicpc.net/problem/1932

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int d[501][501] = { 0, };
	int iValue[501][501] = { 0, };

	int iInput = 0;

	cin >> iInput;

	cin >> iValue[1][1];

	d[1][1] = iValue[1][1];

	for (int i = 2; i <= iInput; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> iValue[i][j];

			d[i][j] = iValue[i][j] + max(d[i - 1][j - 1], d[i - 1][j]);
		}
	}

	for (int i = 1; i <= iInput; ++i)
		d[iInput][0] = max(d[iInput][0], d[iInput][i]);

	cout << d[iInput][0] << endl;
	return 0;
}