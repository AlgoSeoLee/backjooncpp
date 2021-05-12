//https://www.acmicpc.net/problem/10773
//¹ßÇ¥

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	int tmp;
	int result = 0;
	vector <int> vec = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp==0) {
			vec.pop_back();
		}
		else {
			vec.push_back(tmp);
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		result += vec.at(i);
	}
	cout << result << endl;
}