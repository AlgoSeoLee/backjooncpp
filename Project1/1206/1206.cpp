//https://www.acmicpc.net/problem/1206
//¹ßÇ¥

#include<iostream>
#include<deque>
using namespace std;

int main() {
	int n;
	double ave;
	long double average;
	deque <double> dq;
	long double arr[12][12][12];
	int max;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ave;
		dq.push_back(ave);
	}
	for (int a = 0; a <= dq.size(); a++) {
		for (long int i = 0; i <= 10; i++) {
			for (long int j = 0; j <= 10; j++) {
				for (long int l = 1; l < 100; l++) {
					average = (long double)i * (long double)j / (long double)l;
					arr[i][j][l] = floor(average * 1000) / 1000;
					cout << arr[i][j][l] << endl;
					if (dq.at(a)*1000 == arr[i][j][l]*1000) {
						cout << l << endl;
						break;
					}
				}
			}
		}
	}
}