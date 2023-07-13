#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, k, num;
  char order;
  cin >> T;
  while(T--){
    cin >> k;
    multiset<int> m;
    while(k--){
      cin >> order >> num;
      if(order == 'I'){
        m.insert(num);
      }else if(order == 'D'){
        if(m.empty()) continue;
        if(num == 1){
          m.erase(prev(m.end()));
        } else{
          m.erase(m.begin());
        }
      }
    }
    if(m.empty()) cout << "EMPTY\n";
    else cout << *prev(m.end()) << ' ' << *m.begin() << '\n';
  }
}