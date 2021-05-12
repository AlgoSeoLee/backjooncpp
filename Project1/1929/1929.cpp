//https://www.acmicpc.net/problem/1929
//��ǥ

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
    int M, N;
    cin >> M >> N;

    while (M <= N) {
        if (isPrime(M)) {
            cout << M << "\n";
        }
        M++;
    }
    return 0;
}