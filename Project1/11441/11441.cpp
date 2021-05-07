//https://www.acmicpc.net/problem/11441

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int num[100001] = { 0 };
    int sum[100001] = { 0 };
    int n;
    cin >> n;

    cin >> num[1];
    sum[1] = num[1];

    for (int i = 2; i <= n; i++)
    {
        cin >> num[i];
        sum[i] = num[i] + sum[i - 1];
    }

    int m;
    int start, end;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << endl;
    }

    return 0;
}