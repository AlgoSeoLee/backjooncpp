//https://www.acmicpc.net/problem/1364

#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 5) {
		cout << n;
	}
	else if (n > 5 && n < 8) {
		cout << n + 1;
	}
	else
		cout << n + 2;
}