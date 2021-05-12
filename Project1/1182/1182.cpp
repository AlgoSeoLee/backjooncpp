//https://www.acmicpc.net/problem/1182
//¹ßÇ¥

#include <iostream>
using namespace std;

const int MAX = 20;
int N, S;
int arr[MAX];
int result = 0;

void dfs(int idx, int sum){
    sum += arr[idx]; 

    if (idx >= N) {
        return;
    }
    if (sum == S) {
        result++;
    }
    dfs(idx + 1, sum - arr[idx]);
    dfs(idx + 1, sum);
}

int main(void){
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << result << endl;
    return 0;

}