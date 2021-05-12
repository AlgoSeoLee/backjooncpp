//https://www.acmicpc.net/problem/18870
//¹ßÇ¥

#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int temp;
	vector <pair<int, int>> vec;
	vector <int> ans(1000001);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back({temp, i});
	}
	sort(vec.begin(), vec.end());

	int pivot = vec[0].first; 
	int cnt = 0; 
	ans[vec[0].second] = 0; 
	for (int i = 1; i < n; i++) {
		if (pivot == vec[i].first) { 
			ans[vec[i].second] = cnt; 
		} 
		else { 
			ans[vec[i].second] = ++cnt; 
			pivot = vec[i].first; 
		} 
	} 
	for (int i = 0; i < n; i++) { 
		cout << ans[i] << ' '; 
	}

}