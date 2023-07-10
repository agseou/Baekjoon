#include <bits/stdc++.h>
using namespace std;
int N, M;
unordered_map<string, int> m;
string name[100001];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    cin >> name[i];
    m[name[i]] = i;
  }
  while(M--){
    string q;
    cin >> q;
    if(isdigit(q[0])){
      int num = stoi(q);
      cout << name[num] << '\n';
    }
    else cout << m[q] << '\n';
  }
}