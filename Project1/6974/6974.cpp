//https://www.acmicpc.net/problem/6974

#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		cout << a / b << endl;
		cout << a % b << endl;
		cout << endl;
	}

	return 0;
}
