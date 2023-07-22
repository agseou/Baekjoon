#include <bits/stdc++.h>
using namespace std;
int T, n;
string p, q;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while(T--){
    deque<int> dq;
    bool isempty = 0;
    int isreverse = 0;
    cin >> p >> n >> q;

    int cur = 0;
    for(int i = 1; i < q.size()-1; i++){
      if(q[i] == ','){
        dq.push_back(cur);
        cur = 0;
      }
      else
        cur = 10 * cur + (q[i] - '0');
    }
    if(cur != 0) dq.push_back(cur);

    for(auto c : p){
      if(c == 'R') isreverse = 1 - isreverse;
      else if(c == 'D'){
        if(dq.empty()){
        isempty = 1;
        break;
        }
        if(isreverse) dq.pop_back();
        else dq.pop_front();
      }
    }
    
    if(isempty) cout << "error\n";
    else{
      if(isreverse) reverse(dq.begin(), dq.end());
      cout << '[';
      for(int i = 0; i < dq.size(); i++){
        cout << dq[i];
        if(i != dq.size()-1) cout << ',';
      }
      cout << "]\n";
    }
  }
}