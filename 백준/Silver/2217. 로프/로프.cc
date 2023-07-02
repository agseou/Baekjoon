#include <bits/stdc++.h>
using namespace std;
int N;
int maxW[100001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> maxW[i];
  }
  sort(maxW, maxW+N, greater<int>());

  int maxRes=0;
  int tmp;
  for(int i=0;i<N;i++){
    tmp = maxW[i]*(i+1);

    maxRes=max(maxRes, tmp);
  }
  cout<<maxRes<<"\n";
}