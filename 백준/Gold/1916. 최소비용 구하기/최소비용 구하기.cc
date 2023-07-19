#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[1002];
int D[1002];
int N, M, a, b, c;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  fill(D, D+N+1, INF);
  while(M--){
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
  }
  cin >> a >> b;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  D[a] = 0;
  pq.push({D[a],a});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(D[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(D[nxt.Y] <= D[cur.Y] + nxt.X) continue;
      D[nxt.Y] = D[cur.Y] + nxt.X;
      pq.push({D[nxt.Y], nxt.Y});
    }
  }
  cout << D[b];
}