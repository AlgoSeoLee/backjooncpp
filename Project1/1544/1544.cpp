//https://www.acmicpc.net/problem/1544

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string makeString(std::queue<char>& q) {
	string str = "";
	for (int i = 0; i < q.size(); i++) {
		str += q.front();
		q.push(q.front());
		q.pop();
	}

	return str;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; 
	cin >> N;
	vector<string> v;

	for (int i = 0; i < N; i++) {
		string s; 
		cin >> s;

		if (v.size() == 0) {
			v.push_back(s);
		}
		else {
			queue<char> q;

			for (int k = 0; k < s.size(); k++) {
				q.push(s[k]);
			}

			bool issame = false;

			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < s.size(); k++) {
					string compstr = makeString(q);

					if (compstr == v[j]) {
						issame = true;
						break;
					}

					q.push(q.front());
					q.pop();
				}

				if (issame) {
					break;
				}
			}

			if (!issame) {
				v.push_back(s);
			}
		}
	}

	std::cout << v.size() << "\n";

	return 0;
}