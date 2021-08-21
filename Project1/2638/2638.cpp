//https://www.acmicpc.net/problem/2638

#include<iostream> 
#include<vector> 
#include<queue> 
#include<string.h> 

using namespace std; 

int dx[5] ={1,0,-1,0}; 
int dy[5] ={0,1,0,-1}; 
int N,M; 
int paper[101][101]; 
int outAir[101][101]; 
int melt[101][101]; 

struct point{
	int x,y; 
}; 

queue<point> q; 
queue<point> q1; 


void BFS(){

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if (paper[i][j] == 1) {
				q1.push({ i,j });
			}
		} 
	} 
	
	while(!q1.empty()){
		int x = q1.front().x;
		int y = q1.front().y;
		q1.pop(); 
		int cnt = 0; 
		
		for(int i=0;i<4;i++){
			int nx = dx[i] + x;
			int ny = dy[i] + y; 
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			if (outAir[nx][ny] == 1) {
				cnt++;
			}
		}
		
		if (cnt >= 2) {//³ì´Â ºÎºÐ 
			melt[x][y] = 1;
		}
	} 
}

void outsideBFS(){ 
	q.push({0,0}); 
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop(); 
		
		for(int i=0;i<4;i++){
			int nx = dx[i] + x; 
			int ny = dy[i] + y; 
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			if (paper[nx][ny] || outAir[nx][ny]) {
				continue;
			}
			
			outAir[nx][ny] += 1 ;
			q.push({nx,ny}); 
		} 
	} 
}

void meltCheeze(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){ 
			if(melt[i][j]==1) 
				paper[i][j] = 0; 
		} 
	} 
}

int checkMelt(){
	for(int i=0;i<N;i++){ 
		for(int j=0;j<M;j++){ 
			if(paper[i][j]==1) 
				return 0; 
		} 
	} 
	return 1; 
} 

int main(void){

	int ans = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	while (1) {
		if (checkMelt() == 1) {
			break;
		}
		outsideBFS();
		BFS();
		meltCheeze();
		ans++;
		memset(outAir, 0, sizeof(outAir));
		memset(melt, 0, sizeof(melt));
	}
	cout << ans << "\n";
	return 0; 
}