#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string board[102];
int dist[102][102];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  for(int i = 0; i < N; i++)
    cin >> board[i];

  fill(&dist[0][0], &dist[101][102], -1);

  queue<pair<int,int>> Q;
  Q.push({0,0});
  dist[0][0] = 1;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0|| nx >= N || ny < 0 || ny >= M) continue;
      if(dist[nx][ny] != -1 || board[nx][ny] == '0' ) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
    }
  }

  cout << dist[N-1][M-1];
}