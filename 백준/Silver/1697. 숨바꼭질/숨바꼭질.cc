#include <bits/stdc++.h>
using namespace std;
int dist[100002];

int main(void){

	int N, K;
	cin >> N >> K;
	fill(&dist[0], &dist[100001], -1);

	queue<int> Q;
	dist[N] = 0;
	Q.push(N);
	while(dist[K] == -1){
		int cur = Q.front();
		Q.pop();
		for(int i = 0; i < 3; i++){
			int nx = cur;
			if (i == 0) nx += 1;
			if (i == 1) nx -= 1;
			if (i == 2) nx *= 2;

			if(nx < 0 || nx > 100000) continue;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[cur]+1;
			Q.push(nx);
		}
	}
		cout << dist[K] << '\n';
}