//https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector> 
#define SIZE 6
using namespace std;

void dfs(int _n, vector<int>& _num_vec, vector<int>& _one_answer, int _now_idx) {
    int answer_size = _one_answer.size();
    // 사이즈가 원하는사이즈 보다 크면 종료 
    if (answer_size > SIZE) return;

    // 출력하고 끝내기 
    if (answer_size == SIZE) {
        for (int ans_idx = 0; ans_idx < SIZE; ans_idx++)
            cout << _num_vec[_one_answer[ans_idx]] << " ";
        cout << "\n";
        return;
    }

    // 다음 단계 dfs 가능한 노드들을 _one_answer에 추가해주는 구간
    for (int n_idx = _now_idx + 1; n_idx < _n; n_idx++) {
        // 만약, 6개를 채울 수 없는 위치의 인덱스를 선택하면 종료 
        if (answer_size + (_n - n_idx) < SIZE) return;

        _one_answer.push_back(n_idx);
        dfs(_n, _num_vec, _one_answer, n_idx);
        _one_answer.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        // input
        vector<int> num_vec(n, 0);
        vector<int> one_answer;
        for (int n_idx = 0; n_idx < n; n_idx++)
            cin >> num_vec.at(n_idx);

        // dfs 수행
        for (int n_idx = 0; n_idx < n; n_idx++) {
            one_answer.push_back(n_idx);
            dfs(n, num_vec, one_answer, n_idx);
            one_answer.pop_back();
        }

        cout << "\n";
    }
    return 0;
}