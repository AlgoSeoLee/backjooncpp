//https://www.acmicpc.net/problem/11724
//¹ßÇ¥

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

#define MAX_SIZE 1000+1

using namespace std;

void dfs(int start);

vector<int> connected[MAX_SIZE];
bool visited[MAX_SIZE];

void dfs(int start) {
    visited[start] = true;
    for (int i = 0; i < connected[start].size(); i++) {
        int next = connected[start][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m; 
    cin >> n >> m;
    for (int i = 0; i < m; i++) { 
        int u, v;
        cin >> u >> v;
        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    int cnt = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}