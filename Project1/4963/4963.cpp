//https://www.acmicpc.net/problem/4963
//발표

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50

int arr[MAX][MAX];
bool visited[MAX][MAX];

int w, h;
int cnt = 0;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h)
            continue;
        if (arr[nx][ny] == 1 && visited[nx][ny] == false)
            dfs(nx, ny);
    }
}

int main(int argc, const char* argv[]) {
    while (true) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cnt = 0;
        cin >> h >> w;//입력 받는 순서 주의할 것
        if (h == 0 && w == 0) {
            break;
        }
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (arr[i][j] == 1 && visited[i][j] == false) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
