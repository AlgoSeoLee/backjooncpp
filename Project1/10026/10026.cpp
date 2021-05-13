//https://www.acmicpc.net/problem/10026
//¹ßÇ¥

#include <iostream>
using namespace std;

int N;
const int MAX = 101;
char map[MAX][MAX];
bool visited[MAX][MAX] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void DFS_R(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (map[ny][nx] == 'R' && visited[ny][nx] == 0) {
            visited[ny][nx] = true;
            DFS_R(ny, nx);
        }
    }
}

void DFS_G(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (map[ny][nx] == 'G' && visited[ny][nx] == 0) {
            visited[ny][nx] = true;
            DFS_G(ny, nx);
        }
    }
}

void DFS_B(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (map[ny][nx] == 'B' && visited[ny][nx] == 0) {
            visited[ny][nx] = true;
            DFS_B(ny, nx);
        }
    }
}

void resetVisit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {


    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j]; 
        }
    }

    int cntR = 0; 
    int cntG = 0; 
    int cntB = 0; 
    int notColorBlind = 0; 

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R' && visited[i][j] == 0) {
                DFS_R(i, j);
                cntR++;
            }
            if (map[i][j] == 'G' && visited[i][j] == 0) {
                DFS_G(i, j);
                cntG++;
            }
            if (map[i][j] == 'B' && visited[i][j] == 0) {
                DFS_B(i, j);
                cntB++;
            }
        }
    }
    notColorBlind = cntR + cntG + cntB;


    resetVisit();

    cntR = 0; 
    int colorBlind = 0; 

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R' && visited[i][j] == 0) {
                DFS_R(i, j);
                cntR++;
            }
        }
    }
    colorBlind = cntR + cntB;


    cout << notColorBlind << " " << colorBlind;

}