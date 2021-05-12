//https://www.acmicpc.net/problem/11866
//¹ßÇ¥

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int size, num;
	cin >> size >> num;

	queue<int> qu;

	for (int i = 1; i <= size; i++) {
		qu.push(i);
	}

	cout << "<";
	int n;
	while (!qu.empty()) {
		for (int i = 1; i < num; i++) {
			n = qu.front();
			qu.pop();
			qu.push(n);
		}
		if (qu.size() == 1) {
			cout << qu.front() << ">";
			qu.pop();
		}
		else {
			cout << qu.front() << ", ";
			qu.pop();
		}
	}
}