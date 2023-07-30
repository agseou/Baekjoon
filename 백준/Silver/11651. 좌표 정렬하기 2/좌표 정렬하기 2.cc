#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> p;

bool cmp(pair<int,int>& a, pair<int,int>& b){
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  int x, y;

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x >> y;
    p.push_back({x,y});
  }

  sort(p.begin(), p.end(), cmp);
  
  for(auto c : p ) cout << c.first << ' ' << c.second << '\n';
}