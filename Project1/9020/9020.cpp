//https://www.acmicpc.net/problem/9020
//¹ßÇ¥

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
	  if (n <= 1) {
		  return false;
	  }
	  for (int i = 2; i <= sqrt(n); i++) {
		  if ((n % i) == 0) {
	          return false;
	      }
	  }
	  return true;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T;i++) {
        int n, a, b, half;
        cin >> n;
        half = n / 2;
        for (int j = half; j >= 2; j--) {
            a = j;
            b = n - a;
            if (isPrime(a) && isPrime(b)) {
                cout << a << " " << b << '\n';
                break;
            }
        }
    }
}