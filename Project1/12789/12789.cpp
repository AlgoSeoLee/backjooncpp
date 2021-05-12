//https://www.acmicpc.net/problem/12789
//¹ßÇ¥

#include<iostream>
#include<queue>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	queue<int> q1;
	stack<int> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		q1.push(q);
	}
	int count = 1;
	while (!q1.empty()) {
		int cur = q1.front();
		if (cur == count) {
			count++;
			q1.pop();
		}
		else {
			if (!st.empty() && st.top() == count) {
				st.pop();
				count++;
			}
			else
			{
				st.push(cur);
				q1.pop();
			}
		}
	}
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		if (cur != count) {
			cout << "Sad" << '\n';
			return 0;
		}
		count++;
	}
	cout << "Nice" << '\n';
	return 0;
}
