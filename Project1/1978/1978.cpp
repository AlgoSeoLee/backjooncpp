//https://www.acmicpc.net/problem/1978
//¹ßÇ¥

#include <iostream>
using namespace std;

int main() {
	int size;
	cin >> size;
	int total = size;
	int put;

	for (int i = 0; i < size; i++) {
		cin >> put;
		if (put == 1) {
			total--;
			continue;
		}
		for (int j = 2; j < put - 1; j++) {
			if (put % j == 0) {
				total--;
				break;
			}
		}
	}
	cout << total;
}