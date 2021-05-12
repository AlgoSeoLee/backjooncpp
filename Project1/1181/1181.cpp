//https://www.acmicpc.net/problem/1181
//¹ßÇ¥

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    else {
        return a.size() < b.size();
    }
}
int main() {

    vector <string> v;
    string temp;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        v.push_back(word);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        if (temp == v[i])continue;
        cout << v[i] << '\n';
        temp = v[i];
    }
    return 0;
}