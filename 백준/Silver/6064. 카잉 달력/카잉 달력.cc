#include <bits/stdc++.h>
using namespace std;
int T, M, N, x, y;

int GCD(int a, int b){
  if(a == 0) return b;
  return GCD(b%a,a);
}

int LCM(int a, int b){
  if(a == 0) return b;
  return a/GCD(a,b)*b;
}

int sol(int M, int N, int x, int y){
  if(x==M) x = 0;
  if(y==N) y = 0;
  int i = lcm(M,N);
  for(int j = x; j <= i;j+= M){
    if(j == 0) continue;
    if(j%N==y) return j;
    }
  return -1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> M >> N >> x >> y;
    cout << sol(M,N,x,y) << '\n';  
  }
}