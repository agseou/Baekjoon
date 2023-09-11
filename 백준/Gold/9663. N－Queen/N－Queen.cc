#include <bits/stdc++.h>
using namespace std;
bool isused1[20];
bool isused2[20];
bool isused3[20];
int N;
int cnt = 0;

void func(int cur){
  if(cur==N){
    cnt++;
    return;
  }
  for(int i = 0; i < N; i++){
    if(isused1[i] || isused2[i+cur] || isused3[N+cur-i-1]) continue;
      isused1[i] = 1;
      isused2[i+cur] = 1;
      isused3[N+cur-i-1] = 1;
      func(cur+1);
      isused1[i] = 0;
      isused2[i+cur] = 0;
      isused3[N+cur-i-1] = 0;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  func(0);
  cout << cnt;
}