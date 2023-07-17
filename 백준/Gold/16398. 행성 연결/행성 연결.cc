#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> edge;
vector<int> p(1002,-1);

int find(int x){
  if(p[x]<0) return x;
  return p[x]= find(p[x]);
}

bool is_diff_group(int u, int v){
  u = find(u); v = find(v);
  if(u==v) return 0;
  if(p[u]==p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

int main(void){
  int N, cost;
  long long cnt = 0, ans = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> cost;
      if(i==j)continue;
      edge.push_back({cost,i,j});
    }
  }
  sort(edge.begin(),edge.end());
  for(auto e : edge){
    int a, b;
    tie(cost, a, b) = e;
    if(!is_diff_group(a,b)) continue;
    ans+=cost;
    cnt++;
    if(cnt == N-1) continue;
  }
  cout << ans;
}