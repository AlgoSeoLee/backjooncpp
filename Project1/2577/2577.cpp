#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int array[10] = { 0 };
	int r;

	cin >> a >> b >> c;
	r = a * b * c;
	while (r > 0) {
		array[r % 10]++;
		r /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << array[i] << endl;
	}
}