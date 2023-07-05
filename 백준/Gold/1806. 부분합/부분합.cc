#include <bits/stdc++.h>
using namespace std;
int N, S;
int A[100001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> S;
  for(int i = 0; i < N; i++) cin >> A[i];

  int en = 0;
  int len = 100001;
  int sum = A[0];
  for(int st = 0; st < N; st++){
    while(!(sum >= S || en == N)){
      en++;
      if(en != N) sum += A[en];
    }
    if(en == N) break;
    len = min(len, en-st+1);
    sum -= A[st];
  }
  if(len < 100001) cout << len;
  else cout << "0";
}