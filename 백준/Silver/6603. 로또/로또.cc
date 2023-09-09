#include <bits/stdc++.h>
using namespace std;

int K;
int arr[6];
int num[15];
bool isUsed[15];

void func(int L, int st){
  if(L == 6){
    for(int i = 0; i < 6; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i = st; i < K; i++){
    if(!isUsed[i]){
      isUsed[i] = 1;
      arr[L] = num[i];
      func(L+1, i);
      isUsed[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> K;
    if (K == 0) break;
    for(int i = 0; i < K; i++)
      cin >> num[i];
    func(0, 0);
    cout << '\n';
  }
}
