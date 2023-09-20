#include <bits/stdc++.h>
using namespace std;
int N;
int H[1001][3];
int D[1001][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++)
    for(int j = 0; j < 3; j++)
      cin >> H[i][j];

  D[1][0] = H[1][0];
  D[1][1] = H[1][1];
  D[1][2] = H[1][2];

  for(int i = 2; i <= N; i++){
    D[i][0] = min(D[i-1][1],D[i-1][2]) + H[i][0];
    D[i][1] = min(D[i-1][0],D[i-1][2]) + H[i][1];;
    D[i][2] = min(D[i-1][0],D[i-1][1]) + H[i][2];;
  }

  cout << *min_element(D[N], D[N]+3);

}
