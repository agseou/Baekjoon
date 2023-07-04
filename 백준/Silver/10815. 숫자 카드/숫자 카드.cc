#include <bits/stdc++.h>
using namespace std;
int N, M, input;
int ques[20000001];

int isExist(int num){
  if(ques[num+10000000]) return 1;
  else return 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> input;
    ques[input + 10000000]++;
    }
  cin >> M;
  for(int i = 0; i < M ;i++){
    cin >> input;
    cout << isExist(input) << ' ';
  }
}