#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct {
	int x;
	int y;
	int dist;
}info;

int board[1002][1002];
int visit[1002][1002];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int n, m,start_x,start_y;

void bfs() {
	
	queue<info> q;
	q.push({ start_x,start_y,1 });
	visit[start_x][start_y] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if(c_x<0 || c_y < 0 || c_x >= n || c_y >= m || visit[c_x][c_y] == 1 || board[c_x][c_y] == 0)continue;
			q.push({ c_x,c_y,dist + 1 });
			board[c_x][c_y] = dist;
			visit[c_x][c_y] = 1;
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				start_x = i;
				start_y = j;
				board[i][j] = 0;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0 && visit[i][j] == 0) cout << -1 << ' ';			
			else cout << board[i][j]<< ' ';
		}
		cout << '\n';
	}
}