#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool vis[1001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  while(M--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int num = 0;
  for(int i = 1; i <= N; i++){
    if(vis[i]) continue;
    stack<int> s;
    s.push(i);
    vis[i] = true;
    num++;
    while(!s.empty()){
      int cur = s.top();
      s.pop();
      for(auto nxt:adj[cur]){
        if(vis[nxt]) continue;
        s.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  cout << num;
}