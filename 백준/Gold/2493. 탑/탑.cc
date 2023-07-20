#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> s;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, input;
  cin >> N;
  s.push({100000001,0});
  for(int i = 1; i <= N; i++){
    cin >> input;
    while(input > s.top().first)
      s.pop();
    cout << s.top().second << ' ';
    s.push({input,i});
  }
}