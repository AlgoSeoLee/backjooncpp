//https://www.acmicpc.net/problem/14501
//¹ßÇ¥

#include <iostream>
using namespace std;

int main() {
    int N;
    int T[16] = { 0, };
    int P[16] = { 0, };
    int dp[16] = { 0, };
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 > N) {
            dp[i] = dp[i + 1];
            continue;
        }
        dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
    }

    cout << dp[1] << endl;

    return 0;
}