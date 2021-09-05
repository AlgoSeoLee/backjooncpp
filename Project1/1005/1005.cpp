//https://www.acmicpc.net/problem/1005
//¹ßÇ¥

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 1010
using namespace std;

int N, K, D, W;
int Time[MAX];
int Result_Time[MAX];
int Entry[MAX];
vector<int> Build[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        memset(Time, 0, sizeof(Time));
        memset(Result_Time, 0, sizeof(Result_Time));
        memset(Entry, 0, sizeof(Entry));
        for (int i = 0; i < MAX; i++) {
            Build[i].clear();
        }

        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            cin >> Time[i];
        }

        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            Build[a].push_back(b);
            Entry[b]++;
        }

        cin >> W;

        queue<int> Q;

        for (int i = 1; i <= N; i++) {
            if (Entry[i] == 0) {
                Q.push(i);
                Result_Time[i] = Time[i];
            }
        }

        while (Q.empty() == 0) {
            int Cur = Q.front();
            Q.pop();

            for (int i = 0; i < Build[Cur].size(); i++) {
                int Next = Build[Cur][i];
                Result_Time[Next] = max(Result_Time[Next], Result_Time[Cur] + Time[Next]);
                Entry[Next]--;

                if (Entry[Next] == 0) {
                    Q.push(Next);
                }
            }
        }

        cout << Result_Time[W] << endl;
    }

    return 0;
}