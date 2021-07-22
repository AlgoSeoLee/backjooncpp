//https://www.acmicpc.net/problem/2553

#include<iostream>
#include<algorithm>
using namespace std;

long long n, ans;

int main()
{
	cin >> n;
	ans = 1;

	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= 10000000; // 1Ãµ¸¸
		while (ans % 10 == 0)
			ans /= 10;
	}
	cout << ans % 10 << '\n';


}