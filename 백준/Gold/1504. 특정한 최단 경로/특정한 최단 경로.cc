#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[802];
int D[802];
int N, E, a, b, c;

long long CalDist(int st, int en){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  fill(D,D+N+1,INF);
  D[st] = 0;
  pq.push({D[st], st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(D[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(D[nxt.Y] <= D[cur.Y] + nxt.X) continue;
      D[nxt.Y] = D[cur.Y] + nxt.X;
      pq.push({D[nxt.Y], nxt.Y});
    }
  }
  return D[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> E;
  while(E--){
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }

  cin >> a >> b;
  long long ans;
  long long tmp1 = CalDist(1,a) + CalDist(a,b) + CalDist(b,N);
  long long tmp2 = CalDist(1,b) + CalDist(b,a) + CalDist(a,N);
  if(tmp1 < tmp2) ans = tmp1;
  else ans = tmp2;
  if(ans >= INF) cout << "-1";
  else cout << ans;
}