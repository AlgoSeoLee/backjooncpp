//https://www.acmicpc.net/problem/15654

#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

const int MAX = 8; 
int N, M; 
int arr[MAX]; 
vector<int> v; 
bool visited[MAX]; 

void func(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " "; 
		} 
		cout << "\n"; 
		return; 
	} 
	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) {
			continue; 
		} 
		visited[i] = true; 
		arr[idx] = v[i]; 
		func(idx + 1); 
		visited[i] = false; 
	} 
} 

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	cin >> N >> M; 

	v.resize(N); 

	for (int i = 0; i < N; i++) {
		cin >> v[i]; 
	} 
	sort(v.begin(), v.end()); 

	func(0); 
}
