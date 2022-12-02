#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int board[101][101];
int c_board[101][101];

int visit[101][101];

int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };

int day = 0;

queue<pair<int, int>> land;
vector<pair<int, int>> c_land;

void twoLand(int i,int j) {
	queue<pair<int, int>> q;
	visit[i][j] = 1;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int c_x = x+xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || board[c_x][c_y] == 0 || visit[c_x][c_y])continue;
			visit[c_x][c_y] = 1;
			q.push({ c_x,c_y });
		}

	}
	
}

bool twoLandCheck() {

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j]||board[i][j]==0)continue;
			cnt++;
			if (cnt == 2) return true;
			twoLand(i, j);
		}
	}
	return false;
}

void bfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int c_x = x + xx[i];
		int c_y = y + yy[i];
		if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || board[c_x][c_y])continue;
		c_board[x][y] = 1;
		return;
	}
	c_land.push_back({ x,y });
	return;
}

void flood(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c_board[i][j] == 1) {
				board[i][j] = 0;
				c_board[i][j] = 0;
			}
		}
	}
}
void resetVisit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)land.push({ i,j });
		}
	}
	
	while (1) {
		if (land.size() == 0 || land.size() == n * m) {
			cout << -1;
			return 0;
		}
		if (twoLandCheck()) {
			cout << day;
			return 0;
		}
		resetVisit();
		while (!land.empty()) {
			bfs(land.front().first, land.front().second);
			land.pop();
		}
		for (int i = 0; i < c_land.size(); i++) land.push({ c_land[i].first,c_land[i].second });
		c_land.clear();
		flood();
		day++;

	}
	return 0;
}
