#include <iostream>
using namespace std;

int main() {
	int a;
	int max;
	int min;
	
	cin >> a;
	int* p = new int[a];

	for (int i = 0; i < a; i++) {
		cin >> (p[i]);
	}
	min = p[0];
	max = p[0];

	for (int i = 1; i < a; i++) {
		if (p[i] < min) {
			min = p[i];
		}
		if (p[i] > max) {
			max = p[i];
		}
	}
	delete[] p;
	cout << min << " " << max;
}