#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[1002];
int D[1002]; //최단경로
int pre[1002]; //이전경로

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //초기세팅
  int n, m, A, B, C;
  cin >> n >> m;
  fill(D,D+n+1,INF);
  while(m--){
    cin >> A >> B >> C;
    adj[A].push_back({C,B});
  }
  //원하는 출력 정보 입력
  cin >> A >> B;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  D[A] = 0;
  pq.push({D[A],A});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(D[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(D[nxt.Y] <= D[cur.Y] + nxt.X) continue;
      D[nxt.Y] = D[cur.Y] + nxt.X;
      pq.push({D[nxt.Y], nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }
  vector<int> path;
  int cur = B;
  while(cur != A){
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(A);
  reverse(path.begin(), path.end());
  cout << D[B] << '\n';
  cout << path.size() << '\n';
  for(auto x : path) cout << x << ' ';
}