#include <bits/stdc++.h>
using namespace std;
int dx[8] = {0,0,1,-1,0,0};
int dy[8] = {1,-1,0,0,0,0};
int dz[8] = {0,0,0,0,1,-1};
int board[102][102][102];
int dist[102][102][102];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

	int M, N, H;
	cin >> M >> N >> H;

  queue <tuple<int,int,int>> Q;
  fill(&dist[0][0][0], &dist[101][101][101], -1);
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				cin >> board[j][k][i];
        if(board[j][k][i] == 1){
          Q.push({j,k,i});
          dist[j][k][i] = 0;
        }
			}
		}
	}

  //BFS
  while(!Q.empty()){
    auto cur = Q.front();
    Q.pop();
    int curX, curY, curZ;
    tie(curX, curY, curZ) = cur;
    for(int dir = 0; dir < 6; dir++){
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
      if (board[nx][ny][nz] != 0 || dist[nx][ny][nz] != -1) continue;
      Q.push({nx,ny,nz});
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
    }
  }
	

  //안익은 토마토 검사
  int day = 0;
  for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(dist[j][k][i] == -1 && board[j][k][i] != -1){
          cout << -1 << '\n';
          return 0;
        }
        day = max(day, dist[j][k][i]);
      }
		}
	}

  cout << day << '\n';
}
