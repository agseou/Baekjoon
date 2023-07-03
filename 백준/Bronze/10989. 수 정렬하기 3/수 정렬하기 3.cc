#include <bits/stdc++.h>
using namespace std;
int N;
int A[100001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int input;
  for(int i = 0; i < N; i++){
    cin >> input;
    A[input]++;
  }
  for(int i = 1; i <= 10000; i++){
    while(A[i]){
      cout << i << '\n';
      A[i]--;
    }
  }
}