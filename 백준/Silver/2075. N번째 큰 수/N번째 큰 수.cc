#include <bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int>,greater<int>> pq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N;
  for(int i = 0; i < N*N ; i++){
    cin >> M;
    pq.push(M);
    if( N < pq.size()) pq.pop();
  }
  cout << pq.top();
}