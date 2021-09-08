//https://www.acmicpc.net/problem/1094

#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int count = 1;
    int min = 64;
    int sum = 64;

    while (sum > X) {
        min = min / 2;
        if (sum - min >= X) {
            sum -= min;
        }
        else {
            count++;
        }
    }

    cout << count;
    return 0;
}
