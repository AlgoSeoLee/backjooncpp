#include<iostream>
using namespace std;

int main() {
	int a;
	int max = 0;
	double array[1000];
	double r=0;

	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> array[i];
		if (array[i] > max) {
			max = array[i];
		}
	}
	for (int i = 0; i < a; i++)
	{
		array[i] = array[i] / max * 100;
		r += array[i];
	}
	cout << r / a << endl;
}