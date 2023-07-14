#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, K, num;
  cin >> T;
  while(T--){
    long long sum = 0;
    cin >> K;
    priority_queue <long long,vector<long long>,greater<long long>> pq;
    for(int i = 0; i < K; i++){
      cin >> num;
      pq.push(num);
    }
    while(pq.size() > 1){
      long long a = pq.top(); pq.pop();
      long long b = pq.top(); pq.pop();
      sum += a+b;
      pq.push(a+b);
    }
    cout << sum << '\n';
  }
}