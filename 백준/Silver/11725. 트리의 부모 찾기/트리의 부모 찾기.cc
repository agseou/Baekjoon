#include <bits/stdc++.h>
using namespace std;
int P[100001];
vector<int> adj[100001];

void dfs(int cur){
  for(auto nxt : adj[cur]){
    if(P[cur]==nxt) continue;
    P[nxt] = cur;
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, a, b;
  cin >> N;
  for(int i = 0 ; i < N-1; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);
  
  for(int i = 2; i <= N; i++) cout << P[i] << '\n';
}
