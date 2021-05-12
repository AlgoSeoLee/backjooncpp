//https://www.acmicpc.net/problem/1654
//¹ßÇ¥

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int N, M;
long long electricLine[MAX];

bool possible(long long len) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += electricLine[i] / len;
    }
    if (cnt >= M) {
        return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    long long high = 0;

    for (int i = 0; i < N; i++){
        cin >> electricLine[i];
        high = max(high, electricLine[i]);
    }

    long long result = 0;
    long long low = 1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (possible(mid)) {
            if (result < mid) {
                result = mid;
            }
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << result << "\n";
    return 0;
}