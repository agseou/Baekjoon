#include <bits/stdc++.h>
using namespace std;
int N;
vector <bool> V (4000001, true);
vector <int> P;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  V[1] = false;
  for(int i = 2; i*i <= 4000001; i++){
    if(!V[i]) continue;
    for(int j = i*i; j <= 4000001; j+=i)
      V[j]=false;
  }
  for(int i = 2; i < 4000001; i++){
    if(V[i]) P.push_back(i);
  }

  int en = 0;
  int sum = P[0];
  int cnt = 0;
  for(int st = 0; st < P.size(); st++){
    while(!(en == P.size() || sum >= N)){
      en++;
      sum += P[en];
    }
    if(sum == N) cnt++;
    if(en == P.size()) break;
    sum -= P[st];
  }
  cout << cnt;
}