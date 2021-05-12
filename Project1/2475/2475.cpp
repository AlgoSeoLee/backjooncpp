//https://www.acmicpc.net/problem/2475
#include<iostream>
using namespace std;

int main() {
	int n;
	int total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		total += n * n;
	}
	total = total % 10;
	cout << total << endl;
}