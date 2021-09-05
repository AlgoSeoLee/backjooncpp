//https://www.acmicpc.net/problem/1922
//발표

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int MAX = 1000 + 1;

int N, M;

vector<pair<int, int>> graph[MAX];

//minHeap

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

bool visited[MAX];

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    cin >> N >> M;

    for (int i = 0; i < M; i++){
        
        int a, b, c;

        cin >> a >> b >> c;

        //양방향

        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });

    }

    //1번 정점부터 시작

    pq.push({ 0, 1 });

    int result = 0;

    while (!pq.empty()){
        int cost = pq.top().first;
        int vertex = pq.top().second;

        pq.pop();

        if (!visited[vertex]){

            visited[vertex] = true;
            result += cost;

            for (int i = 0; i < graph[vertex].size(); i++){

                int nextCost = graph[vertex][i].first;
                int nextVertex = graph[vertex][i].second;

                if (!visited[nextVertex]) {
                    pq.push({ nextCost, nextVertex });
                }
            }
        }
    }

    cout << result << "\n";

    return 0;

}