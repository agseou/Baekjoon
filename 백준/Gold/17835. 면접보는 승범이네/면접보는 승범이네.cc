#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
const ll INF = 0x7f7f7f7f7f7f;
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
vector<pair<ll,ll>> adj[100002];
ll D[100002];
int N, M, K, U, V;
ll C;

void CalDist(){
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(D[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(D[nxt.Y] > D[cur.Y] + nxt.X){
        D[nxt.Y] = D[cur.Y] + nxt.X;
        pq.push({D[nxt.Y], nxt.Y});
      }
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  while(M--){
    cin >> U >> V >> C;
    adj[V].push_back({C,U});
  }
  fill(D+1,D+N+1,INF);
  while (K--){
    cin >> M;
    D[M] = 0;
    pq.push({D[M], M});
  }

  CalDist();
  
  ll ans = max_element(D+1, D+N+1) - D;
  cout << ans << '\n' << D[ans];
}