//https://www.acmicpc.net/problem/1292
//¹ßÇ¥

#include<iostream>
using namespace std;

int main() {
	int arr[1000] = { 0, };
	int count=0;
	int a=0, b=0;
	int result = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < i && count < 1000; j++) {
			arr[count++] = i;
		}
	}
	cin >> a >> b;
	for (int i = a-1; i <= b-1; i++) {
		result += arr[i];
	}
	cout << result;
}