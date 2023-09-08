/*
#include <bits/stdc++.h>
using namespace std;
int n = 10;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en){
  int mid = (st+en)/2;
}

void merge_sort(int st, int en){
  if(  ) return;
  int mid = (st+en)/2;
  merge_sort(st,mid);
  merge_sort(mid,en);
  merge(st,en);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  merge_sort(0,n);
  for(int i = 0 ;i < n; i++) cout << arr[i] << ' ';
}
*/

#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M;
string board[1001];
int dist[1001][1001][2];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> board[i];

  queue <tuple<int,int,int>> Q;
  Q.push({0,0,0});
  fill(&dist[0][0][0], &dist[1000][1001][2], -1);
  dist[0][0][0] = dist[0][0][1] = 1;

  while (!Q.empty()){
    int x, y, broken;
    tie(x,y,broken) = Q.front();
    Q.pop();
    if(x == N-1 && M-1 == y){
      cout << dist[x][y][broken];
      return 0;
    }
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
        Q.push({nx,ny,broken});
        dist[nx][ny][broken] = dist[x][y][broken] + 1;
      }
      if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1){
        Q.push({nx,ny, 1});
        dist[nx][ny][1] = dist[x][y][broken] + 1;
      }
    }
  }
  cout << "-1";
}
