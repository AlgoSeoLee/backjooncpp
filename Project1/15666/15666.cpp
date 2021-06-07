//https://www.acmicpc.net/problem/15666

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <map> 

using namespace std; 

const int MAX = 8; 
int N, M; 
vector<int> v; 
int arr[MAX]; 
map<int, bool> visited; 

void func(int idx, int start, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << v[arr[i]] << " "; 
		}
		cout << "\n"; 
		return; 
	} 
	for (int i = start; i < v.size(); i++) {
		arr[idx] = i; 
		func(idx + 1, i, cnt + 1); 
	} 
} 

int main() { 
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	
	cin >> N >> M; 
	
	for (int i = 0; i < N; i++) {
		int num; 
		
		cin >> num; 

		if (!visited.count(num)) {
			visited[num] = true; 
			v.push_back(num); 
		} 
	} 
	sort(v.begin(), v.end()); 
	func(0, 0, 0); 
	return 0; 
}
