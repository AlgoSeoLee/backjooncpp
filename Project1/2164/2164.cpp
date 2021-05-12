//https://www.acmicpc.net/problem/2164
//¹ßÇ¥ 

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.back() << endl;
	return 0;
}