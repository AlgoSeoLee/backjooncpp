//https://www.acmicpc.net/problem/1446
//발표

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int idx, val;
};

info tmp;
int dist[10001];
vector<info> v[10001];

int main() {
    int num, goal, s, e, val, before;
    cin >> num >> goal;
    for (int i = 1; i <= goal; i++) {
        dist[i] = i;
    }
    for (int i = 0; i < num; i++) {

        cin >> s >> e >> val;

        if (e - s <= val) { 
            continue;                   //사실상 지름길이 아닌 경우 
        }

        if (e > goal) { 
            continue;                   //목적지를 넘어가는 경우 -> 역주행 불가 
        }    

        tmp.idx = e;
        tmp.val = val;
        v[s].push_back(tmp);

    }

    for (int i = 0; i <= goal; i++) {

        if (i == 0) { 
            before = -1; 
        }

        else 
            before = dist[i - 1];

        dist[i] = min(dist[i], before + 1);
        
        if (!v[i].empty()) {
            for (int k = 0; k < v[i].size(); k++) {
                int to = v[i][k].idx;
                int cost = v[i][k].val;
                if (to > goal) { 
                    continue; 
                }
                if (dist[i] + cost < dist[to]) {
                    dist[to] = dist[i] + cost;
                }
            }
        }
    }
    cout << dist[goal];
    return 0;
}