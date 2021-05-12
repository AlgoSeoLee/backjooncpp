//https://www.acmicpc.net/problem/11050

#include<iostream>
using namespace std;

int factorial(int num) {
	if (num == 0) {
		return 1;
	}
	int result = 1;
	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n - k));
}