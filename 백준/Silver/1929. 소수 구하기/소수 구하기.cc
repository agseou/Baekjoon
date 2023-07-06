#include <bits/stdc++.h>
using namespace std;
int N, M;
vector <bool> V (1000001, true);

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  V[1] = false;
  for(int i = 2; i*i <= M; i++){
    if(!V[i]) continue;
    for(int j = i*i; j <= M; j+=i)
      V[j]=false;
  }
  for(int i = N; i <= M; i++){
    if (V[i]) cout << i << '\n';
  }
}