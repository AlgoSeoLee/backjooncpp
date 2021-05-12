//https://www.acmicpc.net/problem/11659
//¹ßÇ¥

#include <iostream>
using namespace std;

int N, M, pSum[100001];

int main() {
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        pSum[i + 1] = pSum[i] + A;
    }

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        cout << pSum[e] - pSum[s - 1] << '\n';
    }
}