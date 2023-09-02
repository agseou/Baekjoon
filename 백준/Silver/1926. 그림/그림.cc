#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] = {};
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  // n : 세로(행의 수), m : 가로(열의 수) 입력받기
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
    }
  }

  
  int cnt = 0;     // 그림의 개수
  int Size = 0;    // 그림의 크기
  int MaxSize = 0; // 가짱큰 그림의 크기

  // BFS
  for(int i = 0; i < n ; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j] || board[i][j] == 0) continue;
      cnt++;
      Size = 0;
      queue<pair<int, int>> Q; //매번 새로운 pair로 초기화
      vis[i][j] = 1; //방문한 자리에 흔적 남기기
      Q.push({i, j});
      while (!Q.empty())
      { 
        pair<int, int> cur = Q.front();
          Q.pop();
          Size++;
          // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
      }
      // cout << Size << '\n';
      MaxSize = max(Size, MaxSize);
    }
  }
  cout << cnt << '\n' << MaxSize << '\n';
}
