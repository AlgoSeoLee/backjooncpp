//https://www.acmicpc.net/problem/4949
//¹ßÇ¥

#include<iostream>
#include<stack>
#include<string>

using namespace std;

string Check(string str) {
	bool no = false;
	int len = (int)str.length();
	stack<char> st;
	string temp;
	temp = str.substr(len - 1, len);
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (c == '(' || c == '[') {
			st.push(str[i]);
		}
		else if (c == ')') {
			if (!st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				no = true;
				break;
			}
		}
		else if (c == ']') {
			if (!st.empty() && st.top() == '[') {
				st.pop();
			}
			else {
				no = true;
				break;
			}
		}
	}
	if (st.empty() && !no) {
		return "yes";
	}
	else {
		return "no";
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		string str = "";
		getline(cin, str);

		if (str == ".") { 
			break; 
		}
		else cout << Check(str) << endl;
	}

	return 0;
}