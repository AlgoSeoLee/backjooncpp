#include <iostream>
using namespace std;

int main() {
	int n;
	int f;
	int s;
	int sun;
	int r=0;
	int c=0;
	cin >> n;
	if (n < 10) {
		n *= 10;
	}
	r = n;
	while (true) {
		f = r / 10;
		s = r % 10;
		sun = f + s;
		r = (s * 10) + (sun % 10);
		c++;
		if (n == r) {
			break;
		}
	}
	cout << c;
}