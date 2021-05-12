//https://www.acmicpc.net/problem/1009

#include <iostream>
using namespace std;

int main() {
	long a, b;
	int result;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		result = 1;
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			result = (result * a) % 10;
		}
		if (result == 0) {
			cout << 10 << endl;
		}
		else {
			cout << result << endl;
		}
	}
}