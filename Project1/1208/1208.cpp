//https://www.acmicpc.net/problem/1208

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int N, S;

    cin >> N >> S;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    //�迭�� ������ ������

    int half = N / 2;

    //���� �迭 �� ù ��° �迭�� ��� �κ� ������ ���� ����

    vector<int> first(1 << (N - half));

    for (int i = 0; i < 1 << (N - half); i++) {
        for (int j = 0; j < N - half; j++) {
            if (i & (1 << j)) {
                first[i] += v[j];
            }
        }
    }
    //������ �迭�� ��� �κ� ������ ���� ����

    vector<int> second(1 << half);

    for (int i = 0; i < 1 << half; i++) {
        for (int j = 0; j < half; j++) {
            if (i & (1 << j)) {
                second[i] += v[j + (N - half)];
            }
        }
    }
    //�������� ����

    sort(first.begin(), first.end());

    //�������� ����

    sort(second.begin(), second.end(), greater<int>());

    int idx = 0, idx2 = 0;
    long long result = 0;

    while (idx < 1 << (N - half) && idx2 < 1 << half){

        if (first[idx] + second[idx2] == S){
            long long cnt = 1, cnt2 = 1;
            idx++, idx2++;

            while (idx < 1 << (N - half) && first[idx] == first[idx - 1]){
                idx++;
                cnt++;
            }

            while (idx2 < 1 << half && second[idx2] == second[idx2 - 1]){
                idx2++;
                cnt2++;
            }

            result += cnt * cnt2;
        }
        else if (first[idx] + second[idx2] < S) {
            idx++;
        }
        else if (first[idx] + second[idx2] > S) {
            idx2++;
        }
    }

    //�迭�� ������ ���������Ƿ� ������(0)�� ������ �ϳ��ε� �ι� ����

    if (S == 0) {
        result--;
    }

    cout << result << "\n";

    return 0;

}