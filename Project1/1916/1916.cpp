//https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int CITYMAX = 1000 + 1;
const int BUSMAX = 100000 + 1;
const int INF = 987654321;

int n, m;
int source, destination; //�����, ������
vector<pair<int, int>> graph[CITYMAX];

vector<int> dijkstra(int start, int vertex){

    vector<int> distance(vertex, INF); //start�� �������� �Ÿ�
    distance[start] = 0; //�ڱ� �ڽ����� ���� ��� 0
    priority_queue<pair<int, int>> pq; //Cost, Vertex
    pq.push(make_pair(0, start)); //�ʱ� ���� ������

    while (!pq.empty()){
        int cost = -pq.top().first; //�Ÿ��� ��ȣ�� �ٲپ� �Ÿ��� ���� ��������
        int curVertex = pq.top().second;
        pq.pop();

        //�ּҰŸ��� ���ϹǷ�
        if (distance[curVertex] < cost) {
            continue;
        }

        //neighbor �� Ȯ��
        for (int i = 0; i < graph[curVertex].size(); i++){
            int neighbor = graph[curVertex][i].first;
            int neighborDistance = cost + graph[curVertex][i].second;
            //�ּ� ��� �߽߰� ������Ʈ
            if (distance[neighbor] > neighborDistance){
                distance[neighbor] = neighborDistance;
                //�Ÿ��� ��ȣ�� �ٲپ� �Ÿ��� ���� �������� ����������
                pq.push(make_pair(-neighborDistance, neighbor));
            }
        }
    }
    return distance;
}

int main(void){
    cin >> n >> m;
    n++; //������ȣ 1���� ����

    for (int i = 0; i < m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back(make_pair(end, cost));
    }

    cin >> source >> destination;
    vector<int> result = dijkstra(source, n);
    cout << result[destination] << endl; //source->destination �Ÿ�

    return 0;

}