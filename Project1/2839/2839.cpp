//https://www.acmicpc.net/problem/2839

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int n3 = 0;
    int n5 = 0;
    while (N % 5 != 0 && N >= 0) {
        N -= 3;
        n3++;
    }
    if (N < 0) cout << -1 << endl;
    else {
        n5 = N / 5;
        cout << n3 + n5 << endl;
    }

    return 0;
}
