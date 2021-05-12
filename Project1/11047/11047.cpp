//https://www.acmicpc.net/problem/11047

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;
	int c;
	int result = 0;
	vector <int> vec;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> c;
		vec.push_back(c);
	}

	for (int i = n - 1; i >= 0; i--) {
		while (k - vec[i] >= 0) {
			result++;
			k -= vec[i];
		}
	}
	cout << result << endl;

}