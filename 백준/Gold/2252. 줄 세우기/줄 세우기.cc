#include <bits/stdc++.h>
using namespace std;
vector<int> adj[32001];
int deg[32001];
vector<int> res;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, A, B;
  cin >> N >> M;
  while (M--){
    cin >> A >> B;
    adj[A].push_back(B);
    deg[B]++;
  }
  queue<int> q;
  for(int i = 1; i <= N; i++){
    if(!deg[i])q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    res.push_back(cur);
    q.pop();
    for(int nxt: adj[cur]){
      deg[nxt]--;
      if(!deg[nxt]) q.push(nxt);
    }
  }
  for(auto c : res) cout << c << ' ';
}