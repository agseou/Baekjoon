#include <bits/stdc++.h>
using namespace std;
int N, sum;
int S[301];
int D[301];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 1 ; i <= N ; i++) {
    cin >> S[i];
    sum += S[i];
  }
  //초기값 정하기
  D[1]= S[1];
  D[2]= S[2];
  D[3]= S[3];
  for(int i = 4; i <= N; i++){
    D[i] = min(D[i-2], D[i-3]) + S[i];
  }
  cout << sum-min(D[N-1],D[N-2]) << '\n';
}
