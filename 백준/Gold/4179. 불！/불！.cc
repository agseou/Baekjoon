#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1002][1002];
int jihun[1002][1002];
int fire[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
	int R, C;
	cin >> R >> C;

	queue <pair<int,int>> F;
	queue <pair<int,int>> J;
	fill(&fire[0][0], &fire[1001][1001], -1);
	fill(&jihun[0][0], &jihun[1001][1001], -1);


	//맵 입력
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> board[i][j];
			//불 큐에 넣기
			if (board[i][j] == 'F'){
				F.push({i,j});
				fire[i][j] = 0;
			}
			//지훈이 불에 넣기
			if (board[i][j] == 'J'){
				J.push({i,j});
				jihun[i][j] = 0;
			}
		}
	}


	//불 처리
	while(!F.empty()){
		auto cur = F.front();
		F.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if(board[nx][ny] == '#' || fire[nx][ny] != -1) continue;
			F.push({nx,ny});
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
		}
	}

	//지훈 처리
	while(!J.empty()){
		auto cur = J.front();
		J.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= R || ny >= C) {
					cout << jihun[cur.X][cur.Y] + 1;
					return 0;
        }
      if(fire[nx][ny] <= jihun[cur.X][cur.Y] + 1 && fire[nx][ny] != -1) continue;
			if(board[nx][ny] == '#'|| jihun[nx][ny] != -1) continue;
			J.push({nx,ny});
			jihun[nx][ny] = jihun[cur.X][cur.Y] + 1;
			
		}
	}

	cout << "IMPOSSIBLE";

}