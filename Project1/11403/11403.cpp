//https://www.acmicpc.net/problem/11403

#include <iostream>
using namespace std;

const int MAX = 100;
int N;
int graph[MAX][MAX];

void floyd(void){

    //i->j로 가는 길이 없어도
    //k를 거쳐갈 수 있으면 갈 수 있다고 여긴다
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }

}

int main(void){
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    floyd();

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}