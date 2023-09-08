#include <bits/stdc++.h>
using namespace std;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int box[101][101][101];
int dist[101][101][101];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N, H;
  cin >> M >> N >> H;

  //x,y,z 정보 받아야하므로 튜플 사용
  queue<tuple<int,int,int>> Q;
  fill(&dist[0][0][0], &dist[100][101][101], -1);

  //상자에 담긴 토마토 정보 입력
  for(int i = 0; i < H; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        cin >> box[j][k][i];
        if (box[j][k][i] == 1){
          Q.push({j,k,i});
          dist[j][k][i] = 0;
        }
      }
    }
  }

  //BFS
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    int curX, curY, curZ;
    tie(curX, curY, curZ) = cur;
    for(int dir = 0; dir < 6; dir++){
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
      if (box[nx][ny][nz] != 0 || dist[nx][ny][nz] != -1) continue;
      Q.push({nx,ny,nz});
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
    }
  }

  //토마토가 모두 익었는지 검사와 최소 몇일인지 확인
  int day = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < M; k++){
        if(dist[j][k][i] == -1 && box[j][k][i] != -1){
          cout << -1;
          return 0;
        }
        day = max(dist[j][k][i], day);
      }
    }
  }
  cout << day;
}