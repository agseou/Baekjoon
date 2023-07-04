#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[10000001];

long long sol(int mid){
  long long cnt = 0;
  for(int i = 0; i < N; i++){
    if(A[i]-mid>0)
      cnt += A[i]-mid;
  }
  return cnt;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];

  int st = 0;
  int en = *max_element(A,A+N);
  while(st<en){
    int mid = (st+en+1)/2;
    if(sol(mid) >= M) st = mid;
    else en = mid -1;
  }
  cout << st;
}