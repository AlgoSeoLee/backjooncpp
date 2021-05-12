//https://www.acmicpc.net/problem/1259

#include<iostream>
using namespace std;

int main() {
		while (1) {
			bool check = false;
			string a;
			string b;
			cin >> a;
			b = a;
			if (a == "0") break;

			for (int i = 0; i < a.size(); i++) {
				b[i] = a[a.size() - 1 - i];
			}
			for (int i = 0; i < a.size(); i++) {
				if (b[i] != a[i]) {
					check = true;
					break;
				}
			}
			if (check == true) {
				cout << "no" << endl;
			}
			else 
				cout << "yes" << endl;
		}
		return 0;
}
