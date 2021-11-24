#include <iostream>
#include <vector>

using namespace std;

char board[21][21];
int R, C;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int visit[27];
int answer = 1;

void dfs(int x, int y, int cnt) {

	for (int i = 0; i < 4; i++) {
		int c_x = x + xx[i];
		int c_y = y + yy[i];
		if (c_x < 0 || c_y < 0 || c_x >= R || c_y >= C)continue;
		if (visit[board[c_x][c_y] - 'A']) {
			answer = max(answer, cnt);
			continue;
		}
		else {
			visit[board[c_x][c_y] - 'A'] = 1;
			dfs(c_x, c_y, cnt + 1);
			visit[board[c_x][c_y] - 'A'] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	visit[board[0][0] - 'A'] = 1;
	dfs(0, 0,1);
	

	cout << answer;
}
