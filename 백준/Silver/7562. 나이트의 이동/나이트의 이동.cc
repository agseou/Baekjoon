#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[302][302];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void){
	int N;
	cin >> N; //테스트케이스 수
	while(N--){
		int l;
		cin >> l; //체스판 넓이
		pair<int, int> now, goal;
		cin >> now.X >> now.Y >> goal.X >> goal.Y;
		fill(&board[0][0], &board[301][301], -1);

		queue <pair<int,int>> Q;
		board[now.X][now.Y] = 0;
		Q.push({now.X, now.Y});
		while(!Q.empty()){
			auto cur = Q.front();
			Q.pop();
			for(int dir = 0; dir < 8; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
				if (board[nx][ny] != -1) continue;
				board[nx][ny] = board[cur.X][cur.Y] + 1;
				Q.push({nx,ny});
			}
		}
		cout << board[goal.X][goal.Y] << '\n';
	}
}