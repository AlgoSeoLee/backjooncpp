//https://www.acmicpc.net/problem/1026
//¹ßÇ¥

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int tmp;
	int sum = 0;
	vector <int> vec1;
	vector <int> vec2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec1.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec2.push_back(tmp);
	}
	sort(vec1.begin(), vec1.end()); 
	sort(vec2.begin(), vec2.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		sum += vec1[i] * vec2[i];
	}
	cout << sum;
}