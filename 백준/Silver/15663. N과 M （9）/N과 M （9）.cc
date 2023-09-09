#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[10];
int arr[10];
bool isUsed[10];

void func(int K){
  if(K == M){
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for(int i = 0; i < N; i++){
    if(isUsed[i] || tmp == num[i]) continue;
    arr[K] = num[i];
    tmp = arr[K];
    isUsed[i] = 1;
    func(K+1);
    isUsed[i] = 0;
  }
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    cin >> num[i];
  sort(num, num+N);
  func(0);
}
