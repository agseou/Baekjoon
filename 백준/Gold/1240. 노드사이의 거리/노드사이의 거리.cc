#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1001];
bool vis[1001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, u, v, l;
  cin >> N >> M;
  for(int i = 0; i < N-1; i++){
    cin >> u >> v >> l;
    adj[u].push_back({v, l});
    adj[v].push_back({u, l});
  }
  while(M--){
    cin >> u >> v;
    fill(vis, vis+1001, 0);
    stack<pair<int,int>> s;
    s.push({u,0});
    vis[u] = 1;
    while(!s.empty()){
      int cur = s.top().first;
      int dist = s.top().second;
      s.pop();
      if(cur == v){
          cout << dist << '\n';
          break;
        }
      for(auto [nxt, nxtdist] : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        s.push({nxt, dist+nxtdist});
      }
    }

  }
}