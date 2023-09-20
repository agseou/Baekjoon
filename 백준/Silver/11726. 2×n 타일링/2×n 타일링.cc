#include <bits/stdc++.h>
using namespace std;
int N;
int D[1001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  //초기값 정하기
  D[1] = 1;
  D[2] = 2;
  for(int i = 3; i <= N; i++){
    D[i] = (D[i-1]+D[i-2])%10007;
  }

  cout << D[N]%10007;
}
