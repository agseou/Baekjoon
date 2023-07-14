#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; 

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N;
  while(N--){
    cin >> M;
    pq.push(M);
  }
  long long sum = 0;
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    sum += a+b;
    pq.push(a+b);
  }
  cout << sum;
}