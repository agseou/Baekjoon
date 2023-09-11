#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int res = 0;
string board[5];
bool sel[5][5];
bool vis[5][5];
bool isNotUsed[25];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++)
    cin >> board[i];

  fill(isNotUsed+7, isNotUsed+25, true);
  //헤맨이유 : 처음에 사용하는 것을 뽑는 배열로 
  //사용하고자 isUsed를 쓰고 0~6 index에 1을 넣고 코드를 돌림
  //처음부터 사전순으로 가장 작은 순열로 설정되었기 때문에 do-while문은
  //한번만 돌았던 것임! 그래서 반대로 수행하니 작동함!
  do{
    int cnt = 0;
    int Dasom = 0;
    queue<pair<int,int>> Q;

    fill(&vis[0][0],&vis[4][5], 0);
    fill(&sel[0][0],&sel[4][5], 0);

    for(int i = 0; i < 25; i++){
      if(isNotUsed[i]) continue;
      int x = i/5;
      int y = i%5;
      sel[x][y] = 1;
      if(Q.empty()){
        Q.push({x,y});
        vis[x][y] = 1;
      }
    }

    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      cnt++;
      if(board[cur.X][cur.Y] == 'S') Dasom++;
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (vis[nx][ny] || !sel[nx][ny]) continue;
        Q.push({nx,ny});
        vis[nx][ny] = 1;
      }
    }

    if(cnt == 7 && Dasom >= 4) res++;

  }while(next_permutation(isNotUsed,isNotUsed+25));

  cout << res;
}
