#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, age;
  string name;
  cin >> n;

  pair<int, string> v[n];

  for(auto& c : v) cin >> c.first >> c.second;

  stable_sort(v, v+n, [&](pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
  });

  for(auto c : v)
    cout << c.first << ' ' << c.second << '\n';

}