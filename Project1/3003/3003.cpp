//https://www.acmicpc.net/problem/3003

#include<iostream>
using namespace std;

int main() {
	int arr1[6] = { 1,1,2,2,2,8 };
	int arr2[6] = { 0, };
	int arr3[6] = { 0, };
	for (int i = 0; i < 6; i++) {
		cin >> arr2[i];
		if (arr1[i] == arr2[i]) {
			arr3[i] = 0;
		}
		else if (arr1[i] > arr2[i]|| arr1[i] < arr2[i]) {
			arr3[i] = arr1[i] - arr2[i];
		}
	}
	for (int i = 0; i < 6; i++) {
		cout << arr3[i] << " ";
	}
	
}