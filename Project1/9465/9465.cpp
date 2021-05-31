//https://www.acmicpc.net/problem/9465
//¹ßÇ¥

#include<iostream>
#include<algorithm>

using namespace std;

long long d[100001][3];
long long a[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;

	while (t--) {

		int n;

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i][0];
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1];
		}
		for (int i = 1; i <= n; i++) {
			a[i][2] = 0;
		}
		d[0][0] = d[0][1] = d[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]) + a[i][0];
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][1];
			d[i][2] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] }) + a[i][2];
		}
		long long ans;
		ans = max({ d[n][0], d[n][1], d[n][2] });

		cout << ans << '\n';
	}
}