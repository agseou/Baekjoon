#include <bits/stdc++.h>
using namespace std;
int N;
unordered_set<string> s;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  while(N--){
    string name, log;
    cin >> name >> log;
    if(log == "enter") s.insert(name);
    if(log == "leave") s.erase(name);
  }
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for(auto x : ans) cout << x << '\n';
}