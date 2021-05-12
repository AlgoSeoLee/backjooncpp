//https://www.acmicpc.net/problem/1246
//¹ßÇ¥

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	vector <int> v;
	int a;
	int result, max = 0;
	int prise;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		if (m - i < n) {
			result = v[i] * (m - i);
		}
		else {
			result = v[i] * n;
		}
		if (max < result) {
			prise = v[i];
			max = result;
		}
	}
	cout << prise << " " << max << endl;
}