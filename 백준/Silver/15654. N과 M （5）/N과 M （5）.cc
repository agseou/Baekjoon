#include <bits/stdc++.h>
using namespace std;

int N, M;
int input[10];
int arr[10]; // 수열을 담을 배열
bool isUsed[10]; // 특정한 수가 쓰였는지 확인하는 배열

void func(int K){
  if(K == M){ // M개를 모두 선택 -> 출력!
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  // 배열 채우기
  for(int i = 1; i <= N; i++){
    if(!isUsed[i]){
      arr[K] = input[i];
      isUsed[i] = 1;
      func(K+1);
      isUsed[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++)
    cin >> input[i];
  sort(input, input+N+1);
  func(0); //재귀 이용
}
