//https://www.acmicpc.net/problem/1015

#include <iostream>
using namespace std;

int main() {
    int N, arr[51], P[51];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int minIdx = 0;
    for (int i = 0; i < N; i++) {
        int min = 1001;
        for (int j = 0; j < N; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIdx = j;
            }
        }
        P[minIdx] = i;
        arr[minIdx] = 1001;
    }
    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    return 0;
}
