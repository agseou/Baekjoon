#include <bits/stdc++.h>
using namespace std;
int nA, nB;
int A[500001], B[500001];
vector <int> V;
int cnt = 0;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> nA >> nB;
  for (int i = 0; i < nA; i++)
    cin >> A[i];
  for (int i = 0; i < nB; i++)
    cin >> B[i];
  sort(A,A+nA);
  sort(B,B+nB);
  for(int i = 0; i <nA; i++){
    if(!binary_search(B,B+nB,A[i])){
      cnt++;
      V.push_back(A[i]);
    }
  }
  if(cnt == 0) {
    cout << cnt;
    return 0;
  }
  cout << cnt << '\n';
  for(int i = 0 ; i < cnt; i++) cout << V[i] << ' ';
}