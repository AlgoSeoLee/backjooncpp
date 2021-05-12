//https://www.acmicpc.net/problem/1564
//¹ßÇ¥

#include<iostream>
using namespace std;

int main() {
	int n;
	int count=0;
	long long temp = 0;
	long long f=1;

	cin >> n;
	for (long long i = n; i >= 1; i--) {
		f = f * i;
		while (f % 10 == 0) {
			f /= 10;
		}
		f %= 100000000;
	}
	f %= 100000;
	temp = f;
	do {
		temp /= 10;
		count++;
	} while (temp > 0);
	if (count >= 5) {
		cout << f << endl;
	}
	else if (count >= 4) {
		cout << "0" << f << endl;
	}
	else if (count >= 3) {
		cout << "00" << f << endl;
	}
	else if (count >= 2) {
		cout << "000" << f << endl;
	}
	else if (count >= 1) {
		cout << "0000" << f << endl;
	}
	else {
		cout << "00000" << endl;
	}
}