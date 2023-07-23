#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  string s;

  cin >> T;
  while(T--){
    list<char> L;
    auto cur = L.begin();
    cin >> s;
    for(auto c : s){
      if(c == '-'){
        if(cur != L.begin()){ 
          cur--;
          cur = L.erase(cur);}
      }else if(c == '<'){
        if(cur != L.begin()) cur--;
      }else if(c == '>'){
        if(cur != L.end()) cur++;
      }else{
        L.insert(cur,c);
      }
    }
    for(auto c : L) cout << c;
    cout << '\n';
  }
}