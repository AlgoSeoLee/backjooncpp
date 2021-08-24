//https://www.acmicpc.net/problem/1059

#include <iostream>

using namespace std; 

int main() {
	int L;  
	int n; 
	int scaleRight = 1001, scaleLeft = -1001; 
	int arr[51];

	cin >> L;
	for (int i = 0; i < L; ++i) {
		cin >> arr[i]; 
	}

	cin >> n;

	for (int i = 0; i < L; ++i) {
		if (arr[i] - n >= 0) {
			scaleRight = min(scaleRight, arr[i] - n); 
		}
		else {
			scaleLeft = max(scaleLeft, arr[i] - n); 
		} 
	} 
	if (scaleRight != 1001 && scaleLeft != -1001 && scaleRight != 0) {
		cout << abs(scaleRight * scaleLeft) - 1; 
	}
	else if (scaleLeft == -1001 && scaleRight != 0) {
		cout << n * scaleRight - 1; 
	}
	else if (scaleRight == 0){
		cout << 0; 
	} 

	return 0; 
}