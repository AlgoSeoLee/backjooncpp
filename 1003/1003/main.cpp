#include<iostream>
using namespace std;
long long fiboarr[50] = { 0,1, };
long long fibo(int N)
{
	if (N == 0 || N == 1)
		return fiboarr[N];
	else if (fiboarr[N] == 0)
		fiboarr[N] = fibo(N - 1) + fibo(N - 2);
	return fiboarr[N];
}

int main() {

	int n;// ют╥б
	int r; // х╫╪Ж


	cin >> r;
	while (r--) {
		cin >> n;

		if (n == 0) {
			cout << "1 0" << endl;
		}
		else {
			cout << fibo(n - 1) << " " << fibo(n) << endl;
		}
	}
	return 0;
}