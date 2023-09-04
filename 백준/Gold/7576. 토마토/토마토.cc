#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[1002][1002];
int dist[1002][1002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N;
  cin >> M >> N;

  queue<pair<int,int>> Q;
  fill(&dist[0][0], &dist[1001][1002], -1);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      if (board[i][j] == 1){
        Q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
    }
  }

  int cnt = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(dist[i][j] == -1 && board[i][j] != -1){
        cout << -1;
        return 0;
      }
      cnt = max(cnt, dist[i][j]);
    }
  }
  cout << cnt;
}