//https://www.acmicpc.net/problem/1448
//¹ßÇ¥

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int tmp;
	int result = 0;
	vector <int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), greater<int>());

	for(int i= 0;i<(vec.size()-2);i++){
		if (vec[i] < vec[i + 1] + vec[i + 2]) {
			result = vec[i] + vec[i + 1] + vec[i + 2];
			break;
		}
		else {
			result = -1;
		}
	}
	cout << result << endl;
}