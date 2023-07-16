#include <bits/stdc++.h>
using namespace std;
vector<int> adj[501];
bool vis[501];
int cnt = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    int n, m, u, v;
    cin >> n >> m;
    
    //종료조건
    if(n==0&&m==0) break;
    cnt++;

    fill(vis,vis+n+1,0);
    for(int i = 1; i <= n; i++) adj[i].clear();

    //m개의 간선 입력
    while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    //트리 세기 -> BFS
    int tree = 0;
    queue<pair<int,int>> q;

    for(int i = 1; i <= n; i++){
      bool istree = 1;
      if(vis[i]) continue;
      vis[i] = 1;
      q.push({i,0});
      while(!q.empty()){
        int cur = q.front().first;
        int p = q.front().second;
        q.pop();
        for(auto nxt : adj[cur]){
          if(nxt == p) continue;
          if(vis[nxt]){
            istree = 0;
            break;
          }
          q.push({nxt,cur});
          vis[nxt] = 1;
        }
      }
      tree += istree;
    }

    //출력부
    cout << "Case " << cnt << ": ";
    if(tree==1) cout << "There is one tree.\n";
    else if(tree > 1) cout << "A forest of " << tree << " trees.\n";
    else if(tree == 0) cout << "No trees.\n";
  }
}
