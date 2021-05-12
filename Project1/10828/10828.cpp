//https://www.acmicpc.net/problem/10828
//¹ßÇ¥

#include <iostream>
#include <string>
using namespace std;

#define maxVal 10001

class Stack
{
public:
	void push(int x) {
		data[++topidx] = x;
	}
	int pop() {
		if (empty()) return -1;
		else return data[topidx--];
	}
	int size() {
		return topidx + 1;
	}
	int empty() {
		return topidx == -1;
	}
	int top() {
		if (empty()) return -1;
		else return data[topidx];
	}


private:
	int data[maxVal];
	int topidx = -1;

};

int main() {

	int n;
	cin >> n;
	string str;
	Stack stk;
	int x = 0;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			stk.push(x);
		}
		else if (str == "top") {
			cout << stk.top() << "\n";
		}
		else if (str == "pop") {
			cout << stk.pop() << "\n";
		}
		else if (str == "size") {
			cout << stk.size() << "\n";
		}
		else if (str == "empty") {
			cout << stk.empty() << "\n";
		}
	}
}

