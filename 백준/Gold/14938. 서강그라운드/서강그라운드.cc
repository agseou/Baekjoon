#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int field[105][105];
int nxt[105][105];
int item[105];
bool vis[105];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, r, t, a, b, l;
  cin >> n >> m >> r;
  fill(&field[0][0],&field[101][102], INF);
  for(int i = 0; i <= n; i++) field[i][i] = 0;
  //필드 별 아이템 개수 입력 받기
  for(int i = 1; i <= n; i++) cin >> item[i];
  //필드 정보 입력받기
  while(r--){
    cin >> a >> b >> l;
    field[a][b] = l; field[b][a] = l;
    nxt[a][b] = b; nxt[b][a] = a;
  }
  //최단거리계산
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++){
        if(field[i][j] > field[i][k]+field[k][j]){
          field[i][j] = field[i][k]+field[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    int cnt = 0;
    fill(vis,vis+n+1,0);
    for(int j = 1; j <= n; j++){
      if(field[i][j] > m) continue;
      int st = i;
      while(st != j){
        st = nxt[st][j];
        vis[st] = 1;
      }
      vis[j] = 1;
    }
    for(int j = 1; j <= n; j++){
      if(vis[j]) cnt += item[j];
    }
    ans = max(ans,cnt);
  }
  cout << ans;
}