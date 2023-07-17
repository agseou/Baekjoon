#include <bits/stdc++.h>
using namespace std;
tuple<int,int,int> edge[100005];
vector<int> p(10005,-1);

int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int V, E, A, B ,C;
  int ans = 0, cnt = 0;
  cin >> V >> E;
  for(int i = 0; i < E; i++){
    cin >> A >> B >> C;
    edge[i] = {C,A,B}; //가중치, A정점, B정점
  }
  sort(edge,edge+E);
  
  for(int i = 0; i < E; i++){
    tie(C,A,B) = edge[i];
    if(!is_diff_group(A,B)) continue;
    ans += C;
    cnt++;
    if(cnt == V-1) break;
  }
  cout << ans;
}