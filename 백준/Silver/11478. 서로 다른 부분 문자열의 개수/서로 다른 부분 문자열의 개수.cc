#include <bits/stdc++.h>
using namespace std;
string S;
unordered_set<string> n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> S;
  for(int i = 0; i < S.size(); i++){
    for(int j = 1; j <= S.length(); j++){
        n.insert(S.substr(i,j));
    }
  }
  cout << n.size();
}