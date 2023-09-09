#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[10];
int arr[10]; // 수열을 담을 배열

void func(int K, int st){
  if(K == M){ // M개를 모두 선택 -> 출력!
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  // 배열 채우기
  int tmp = 0;
  for(int i = st; i < N; i++){
    if(tmp == num[i]) continue;
    arr[K] = num[i];
    tmp = arr[K];
    func(K+1, i+1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    cin >> num[i];
  sort(num, num+N);
  func(0, 0); //재귀 이용
}