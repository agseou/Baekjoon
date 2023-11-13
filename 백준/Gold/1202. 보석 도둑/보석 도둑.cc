#include <bits/stdc++.h>
using namespace std;


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  pair<int,int> info[300001];
  multiset<int> bag;
  for(int i = 0; i < N; i++)
    cin >> info[i].second >> info[i].first;
  sort(info,info+N);
  for(int i = 0; i < K; i++){
    int num;
    cin >> num;
    bag.insert(num);
  }

  long long ans = 0;

  for(int i = N-1; i >= 0; i--){
    int m, v;
    tie(v,m) = info[i];
    auto iter = bag.lower_bound(m);
    if(iter == bag.end()) continue;
    ans += v;
    bag.erase(iter);
  }
  cout << ans;
}