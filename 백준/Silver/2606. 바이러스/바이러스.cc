#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101];
bool vis[101];
int res = 0;

void dfs(int cur){
  vis[cur] = 1;
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    res++;
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, u, v;
  cin >> N >> M;
  while(M--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << res;
}