//https://www.acmicpc.net/problem/1440

#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
using namespace std;

int main() {
	int time, minute, second;
	string str;
	string stringBuffer;
	vector<string> vec;
	cin >> str;
	istringstream ss(str);
	while (getline(ss, stringBuffer, ':')) {
		vec.push_back(stringBuffer);
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] <= "12") {
			time++;
		}
		else {
			minute++;
			second++;
		}
	}
}