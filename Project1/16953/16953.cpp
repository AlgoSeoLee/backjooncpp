//https://www.acmicpc.net/problem/16953
//น้มุ

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int mini = 10000;
long long A, B, cnt;

void bfs(long long a, int cnt)
{
	if (a > B) return;

	if (a == B)
	{
		mini = min(mini, cnt);
	}
	bfs(a * 2, cnt + 1);
	bfs(a * 10 + 1, cnt + 1);

}

int main()
{
	cin >> A >> B;

	bfs(A, 1);

	if (mini == 10000) cout << -1;
	else cout << mini;
}