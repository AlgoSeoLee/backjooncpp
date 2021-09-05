//https://www.acmicpc.net/problem/1647
//��ǥ

#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
#define MAX 100000 + 1
using namespace std;

int N, M, Answer;
int Parent[MAX];
vector < pair<int, pair<int, int>>> Edge;
vector<int> V;


int Find_Parent(int x)
{
    if (x == Parent[x]) { 
        return x; 
    }
    else 
        return Parent[x] = Find_Parent(Parent[x]);
}

void Union(int x, int y, int Cost)
{
    x = Find_Parent(x);
    y = Find_Parent(y);

    if (x == y) { 
        return; 
    }
    else
        Parent[y] = x;
    N--;
}

bool Same_Parent(int x, int y)
{
    x = Find_Parent(x);
    y = Find_Parent(y);

    if (x == y) return true;
    else return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(Edge.begin(), Edge.end());
    for (int i = 1; i <= N; i++) {
        Parent[i] = i;
    }

    for (int i = 0; i < Edge.size(); i++)
    {
        if (Same_Parent(Edge[i].second.first, Edge[i].second.second) == false)
        {
            Union(Edge[i].second.first, Edge[i].second.second, Edge[i].first);
            V.push_back(Edge[i].first);
        }
    }

    for (int i = 0; i < V.size() - 1; i++)
    {
        Answer = Answer + V[i];
    }
    cout << Answer << endl;

    return 0;
}