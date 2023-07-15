#include <bits/stdc++.h>
using namespace std;
vector<int> adj[501];
stack<int> s;
bool vis[501];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int res = 0, cnt = 0;
  s.push(1);
  while(!s.empty()){
    if(cnt==2) break;
    int cur = s.top();
    s.pop();
    vis[cur] = 1;
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      res++;
      if(cur==1)s.push(nxt);
    }
  }

  cout << res;
}