#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct {
	int x;
	int y;
	int start_x;
	int start_y;
	int cnt;
}info;

int visit[52][52];
char board[52][52];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int n, m;
int cut = 0;
string answer = "No";
/*void bfs() {

	queue<info> q;
	q.push({ 0,0,0,0,1 });
	visit[0][0] = 1;

	while (!q.empty()) {
		
		int x = q.front().x;
		int y = q.front().y;
		int start_x = q.front().start_x;
		int start_y = q.front().start_y;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			
			int c_x = x + xx[i];
			int c_y = y + yy[i];

			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m)continue;
			if (cnt >= 4 && visit[c_x][c_y] == 1 &&(start_x==c_x)&&(start_y==c_y)) {
				answer = "Yes";
				return;
			}
			if (visit[c_x][c_y] == 1)continue;
			if (board[c_x][c_y] == board[x][y]) {
				q.push({ c_x,c_y,start_x,start_y,cnt + 1 });
			}
			else {
				q.push({ c_x,c_y,c_x,c_y,1 });
			}
			visit[c_x][c_y] = 1;
		}
	}

}*/
void dfs(int start_x,int start_y,int cnt,int x,int y) {
	vector<info> v;
	if (cut == 1)return;
	for (int i = 0; i < 4; i++) {
		int c_x = x + xx[i];
		int c_y = y + yy[i];
		if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m)continue;
		if (cnt >= 4 && visit[c_x][c_y] == 1 && (start_x == c_x) && (start_y == c_y)) {
			answer = "Yes";
			cut == 1;
			return;
		}
		if (visit[c_x][c_y] == 1||board[x][y]!=board[c_x][c_y])continue;
		visit[c_x][c_y] = 1;
		dfs(start_x, start_y, cnt + 1, c_x, c_y);
		visit[c_x][c_y] = 0;
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 1;
			dfs(i,j,1,i,j);
			if (cut == 1)break;
		}
		if (cut == 1)break;
	}
	
	cout << answer;

}
