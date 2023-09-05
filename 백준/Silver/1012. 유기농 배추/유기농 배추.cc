#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool board[51][51];
bool vis[51][51];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, M, N, K, x, y;
  cin >> T; 
  
  while(T--){
    cin >> M >> N >> K;

    fill(&board[0][0], &board[50][51], 0);
		fill(&vis[0][0], &vis[50][51], 0);

    while(K--){
      cin >> x >> y;
      board[y][x] = 1;
    }

    int BaeChu = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(!board[i][j] || vis[i][j]) continue;
        queue<pair<int,int>> Q;
        Q.push({i,j});
        vis[i][j] = 1;
        BaeChu++;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(!board[nx][ny] || vis[nx][ny]) continue;
            Q.push({nx,ny});
            vis[nx][ny] = 1;
          }
        }
      }
    }
    cout << BaeChu << '\n';
  }

}