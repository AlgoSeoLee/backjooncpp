//https://www.acmicpc.net/problem/14938
//발표

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define INF 1000000000 // 10억

int ans;
int n, m, r, a, b, l;
int local[101];
int d[101];
vector<pair<int, int>> v[101];

void dijkstra(int start)
{
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		d[i] = INF;

	d[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		int dist = d[node];
		q.pop();

		for (int i = 0; i < v[node].size(); i++)
		{
			int next_node = v[node][i].first;
			int next_dist = v[node][i].second;

			if (d[next_node] > dist + next_dist)
			{
				d[next_node] = dist + next_dist;
				q.push(next_node);
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] <= m) {
			cnt += local[i];
		}
	}
	ans = max(ans, cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	// 지역별 아이템 갯수 저장
	for (int i = 1; i <= n; i++) { 
		cin >> local[i]; 
	}

	// 길과 길 사이의 거리 저장
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b >> l;
		v[a].push_back({ b,l });
		v[b].push_back({ a,l });
	}

	for (int i = 1; i <= n; i++)
		dijkstra(i);

	cout << ans;

}