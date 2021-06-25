//https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 + 1;

int N;
bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void findParent(int nodeNum){

    visited[nodeNum] = true; //�湮�� ��� ǥ��

    //DFS
    for (int i = 0; i < tree[nodeNum].size(); i++){

        int next = tree[nodeNum][i];

        if (!visited[next]){

            parent[next] = nodeNum; //next�� parent�� nodeNum
            findParent(next);

        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin �ӵ� ��� ����

    cin >> N;

    for (int i = 0; i < N - 1; i++){

        int node1, node2;

        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);

    }

    findParent(1); //root����


    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;

}