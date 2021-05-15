//https://www.acmicpc.net/problem/11399

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int N;
int person[MAX];

int main(){

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> person[i];
    }

    sort(person, person + N);

    int time = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            time += person[j];
        }
    }

    cout << time << endl;

    return 0;

}