#include <bits/stdc++.h>
using namespace std;
int K, N;
int lan[100001];
#define ll long long

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> N;
  for(int i = 0; i < K ; i++) cin >> lan[i];
  ll st = 1; //랜선 가장 짧은 길이
  ll en = pow(2,31)-1; //랜선 가장 긴 길이
  while(st < en){ //st와 en이 같아질 때까지 반복
    ll mid = (st+en+1)/2; //1을 더하지 않으면 st와 en이 1차이나는 경우 무한루프에 빠짐
    ll cnt = 0;
    for(int i = 0; i < K; i++)
      cnt += lan[i]/mid;
    if(cnt >= N) st = mid;
    else en = mid - 1;
  }
  cout << st;
}