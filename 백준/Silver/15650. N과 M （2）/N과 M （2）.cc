#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];
bool isused[10];

void func(int cur){
  if( cur == M){
    for(int i = 0; i < M; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  int start = 1;
  if(cur != 0) start = arr[cur - 1] + 1;
  for(int i = start; i <= N; i++){
    if(isused[i]) continue;
    arr[cur] = i;
    isused[i] = 1;
    func(cur+1);
    isused[i] = 0;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  func(0);
}