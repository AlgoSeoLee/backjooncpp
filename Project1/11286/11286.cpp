//https://www.acmicpc.net/problem/11286

#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main() {
    cin.sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int N, num;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num) {
            pq.push({ abs(num), num });
        }
        else {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}