#include <bits/stdc++.h>
using namespace std;
int city[101][101];
const int INF = 0x3f3f3f3f;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a, b, c;
  fill(&city[0][0],&city[100][101], INF);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> c;
    city[a][b] = min(city[a][b], c);
  }

  for(int i = 1; i <= n; i++) city[i][i] = 0;

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        city[i][j] = min(city[i][j], city[i][k]+city[k][j]);
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(city[i][j] == INF) cout << "0 ";
      else cout << city[i][j] << ' ';
    }
    cout << '\n';
  }
}