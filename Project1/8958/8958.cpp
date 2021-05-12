#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char array[80];
	int score = 0;
	int m;
	int sum = 0;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> array;

		for (int j = 0; j < strlen(array); j++) {
			if (array[j] == 'O') {
				score++;
				sum += score;

			}
			if (array[j] == 'X') {
				score = 0;
			}
		}
		cout << sum << endl;
		sum = 0; 
		score = 0;

	}
	
}