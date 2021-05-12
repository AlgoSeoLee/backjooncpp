//https://www.acmicpc.net/problem/18111
//¹ßÇ¥

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int land[501][501] = { 0, };
	int N, M, B;

	cin >> N >> M >> B;

	int min = 256;
	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];

			if (land[i][j] < min)
				min = land[i][j];

			if (land[i][j] > max)
				max = land[i][j];
		}
	}

	int time = INT_MAX;
	int height = 0;

	bool can_build = false;

	for (int i = min; i <= max; i++) {
		int sum_build = 0;
		int sum_remove = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int temp = i - land[j][k];

				if (temp < 0)
					sum_remove += temp * -1;
				else
					sum_build += temp;
			}
		}

		if (sum_build <= sum_remove + B) { 
			int temp = sum_build + sum_remove * 2; 
			if (time > temp) {
				time = temp;
				height = i;
			}

			if (temp == time)
				if (height < i)
					height = i;
		}
	}
	cout << time << " " << height << endl;
}