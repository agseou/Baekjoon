#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
vector <pair<int,int>> adj[1002];
int D[1002];
int N, M, K, A, B, T;

int CalTime(int st, int en){
  fill(D,D+N+1,INF);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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

  cin >> N >> M >> K;
  while(M--){
    cin >> A >> B >> T;
    adj[A].push_back({T,B});
  }
  int ans = 0;
  for(int i = 1; i <= N; i++)
    ans = max(ans, CalTime(i,K)+CalTime(K,i));
  cout << ans;
}