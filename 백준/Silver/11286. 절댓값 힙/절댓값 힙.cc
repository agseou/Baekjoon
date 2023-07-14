#include <bits/stdc++.h>
using namespace std;

//priority_queue는 class를 만들어 비교함수
class cmp{
  public:
    bool operator() (int a, int b){
      if(abs(a) != abs(b)) return abs(a) > abs(b);
      return a>0 && b<0;
    }
};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, cmp> pq;
  int N, M;
  cin >> N;
  while(N--){
    cin >> M;
    if(M == 0){
      if(pq.empty()) cout << "0\n";
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }else pq.push(M);
  }

}