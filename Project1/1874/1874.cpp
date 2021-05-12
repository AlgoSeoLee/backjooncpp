//https://www.acmicpc.net/problem/1874
//¹ßÇ¥

#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, num, cnt = 1;
	stack<int> s;
	string result = "";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num >= cnt) {
			while (num + 1 != cnt) {
				s.push(cnt++);
				result += "+\n";
			}
			s.pop();
			result += "-\n";
		}
		else {
			if (s.top() == num) {
				s.pop();
				result += "-\n";
			}
			else {
				result = "NO";
				break;
			}
		}
	}
	cout << result;

	return 0;
}