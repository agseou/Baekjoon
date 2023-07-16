#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int deg[1001];
vector<int> res;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, num, a, b;
  cin >> N >> M;
  while(M--){
    cin >> num;
    cin >> a;
    while(--num){
      cin >> b;
      adj[a].push_back(b);
      deg[b]++;
      a = b;
    }
  }

  queue<int> q;
  for(int i = 1; i <= N; i++)
    if(!deg[i]) q.push(i);

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    res.push_back(cur);
    for(auto nxt : adj[cur]){
      deg[nxt]--;
      if(deg[nxt]==0) q.push(nxt);
    }
  }
  if(N == res.size()) for(auto c : res) cout << c << '\n';
  else cout << '0';
}