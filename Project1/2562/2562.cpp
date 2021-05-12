#include <iostream>
using namespace std;

int main() {
	int array[100];
	int max = 0;
	int n;

	for (int i = 1; i < 10; i++) {
		cin >> array[i];
		if (max < array[i]) {
			max = array[i];
			n = i;
		}
	}
	cout << max << endl << n;
}