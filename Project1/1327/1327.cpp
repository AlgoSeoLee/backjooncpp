//https://www.acmicpc.net/problem/1327

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int N, K;

int BFS(string s){

    queue<pair<string, int>> q;
    q.push({ s, 0 });
    map<string, bool> visited;
    string target = s;
    sort(target.begin(), target.end()); //오름차순

    while (!q.empty()){

        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == target) {
            return cnt;
        }


        if (!visited.count(cur)){
            visited[cur] = true;

            //모든 경우를 다 해본다

            for (int j = 0; j <= N - K; j++){
                string temp = cur.substr(j, K);
                reverse(temp.begin(), temp.end());

                //j부터 K개의 문자를 선택하여 뒤집는다

                q.push({ cur.substr(0, j) + temp + cur.substr(j + K, cur.size()), cnt + 1 });

            }
        }
    }
    return -1;
}

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    string s;

    for (int i = 0; i < N; i++){

        char c;
        cin >> c;

        s += c;
    }

    cout << BFS(s) << "\n";

    return 0;
}