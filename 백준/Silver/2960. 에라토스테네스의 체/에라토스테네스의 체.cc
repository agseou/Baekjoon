#include <bits/stdc++.h>
using namespace std;
int N, K;
vector <bool> V(1001,true);

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  
  for(int i = 2; i <= N; i++){
    if(!V[i]) continue;
    for(int j = i; j <= N; j += i){
      if (!V[j]) continue;
      V[j] = false;
      K--;
      if(K == 0) {
        cout << j;
        return 0;
      }
    }
  }
}