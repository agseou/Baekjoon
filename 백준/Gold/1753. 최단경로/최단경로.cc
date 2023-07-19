#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[20002];
int D[20002]; //최단거리 표

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int V, E, K, u, v, w;
  cin >> V >> E >> K;
  fill(D,D+V+1,INF);

  while(E--){
    cin >> u >> v >> w;
    adj[u].push_back({w,v}); //간선 정보 입력
  }

  //우선순위큐 선원 -> 최소힙으로!
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  D[K] = 0; //시작 정점에 0
  pq.push({D[K],K}); //시작정점 넣기

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(D[cur.Y] != cur.X) continue; //최단거리표의 입력된 정보와 다름 스킵
    for(auto nxt : adj[cur.Y]){ //간선이 가리키는 다음 정점 정보 nxt 대입
      if(D[nxt.Y] <= D[cur.Y]+nxt.X) continue;
      D[nxt.Y] = D[cur.Y]+nxt.X;
      pq.push({D[nxt.Y], nxt.Y});
    }
  }

  for(int i = 1; i <= V; i++){
    if(D[i]==INF) cout << "INF\n";
    else cout << D[i] << '\n';
  }
}