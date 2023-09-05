#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[102][102];
char board2[102][102];
bool vis[102][102];

int main(void){

	int N;
	cin >> N;
	
	//색 입력
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
			if (board[i][j] == 'G') board2[i][j] = 'R';
			else board2[i][j] = board[i][j];
		}
	}

	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (vis[i][j]) continue;
			queue <pair<int,int>> Q;
			cnt++;
			Q.push({i,j});
			vis[i][j] = 1;
			while(!Q.empty()){
				auto cur = Q.front();
				Q.pop();
				for(int dir = 0; dir < 4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if(vis[nx][ny] || board[cur.X][cur.Y] != board[nx][ny]) continue;
					vis[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
		}
	}
	fill(&vis[0][0], &vis[101][101], 0);
	int cnt2 = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (vis[i][j]) continue;
			queue <pair<int,int>> Q;
			cnt2++;
			Q.push({i,j});
			vis[i][j] = 1;
			while(!Q.empty()){
				auto cur = Q.front();
				Q.pop();
				for(int dir = 0; dir < 4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if(vis[nx][ny] || board2[cur.X][cur.Y] != board2[nx][ny]) continue;
					vis[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
		}
	}
	cout << cnt << ' ' << cnt2;
}