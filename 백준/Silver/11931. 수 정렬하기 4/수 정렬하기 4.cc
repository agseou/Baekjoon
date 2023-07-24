#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n;
  for(int i = 0;i < n; i++){
    cin >> m;
    a.push_back(m);
  }
  sort(a.begin(), a.end(), greater<int>());
  for(auto c : a) cout << c << '\n';
}