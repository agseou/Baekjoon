#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10]; // 수열을 담을 배열

void func(int K){
  if(K == M){ // M개를 모두 선택 -> 출력!
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  // 배열 채우기
  int st = 1;
  if(K != 0) st = arr[K-1];
  for(int i = st; i <= N; i++){
    arr[K] = i;
    func(K+1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  func(0); //재귀 이용
}
