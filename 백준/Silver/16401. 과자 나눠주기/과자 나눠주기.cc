#include <bits/stdc++.h>
using namespace std;
int M, N;
int A[1000001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> M >> N;
  for(int i = 0; i < N; i++)
    cin >> A[i];

  int st = 0;
  int en = *max_element(A, A+N);
  while(st<en){
    int mid = (st+en+1)/2;
    int cnt = 0;
    for(int i = 0; i < N; i++){
      cnt += A[i]/mid;
    }
    if(M > cnt)
      en = mid - 1;
    else
      st = mid;
  }
  cout << st;
}