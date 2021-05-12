//https://www.acmicpc.net/problem/1157

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int arr[26] = { 0, };
	int max = 0;
	int index = 0;
	int count = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		int n = str[i];

		if (n < 97) {
			arr[n - 65]++;
		}
		else {
			arr[n - 97]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}

	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			count++;
			if (count >= 2) {
				cout << "?" << endl;
				return 0;
			}
		}
	}

		cout << (char)(index + 65) << endl;
		return 0;
	
}