#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

int board[1002][1002];
int visit[1002][1002];
int group[100001];
int group_visit[100001];


int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,1,-1 };
int n, m;
vector<int> reset;

typedef struct {
	int x;
	int y;
}info;
int check(int a, int b) {
	int check_cnt = 1;
	
	for (int i = 0; i < 4; i++) {
		int c_x = a + xx[i];
		int c_y = b + yy[i];
		if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || group_visit[board[c_x][c_y]] == 1)continue;
		check_cnt += group[board[c_x][c_y]];
		group_visit[board[c_x][c_y]] = 1;
		reset.push_back(board[c_x][c_y]);
	}
	
	for (int i = 0; i < reset.size(); i++) {
		group_visit[reset[i]] = 0;
	}
	
	reset.clear();
	return check_cnt;
}

int bfs(int a, int b, int r) {

	int box_cnt = 1;
	queue<info> q;

	q.push({ a,b });
	visit[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || board[c_x][c_y] == 0 || visit[c_x][c_y] == 1)continue;
			q.push({ c_x,c_y });
			box_cnt++;
			board[c_x][c_y] = r;
			visit[c_x][c_y] = 1;
		}
	}
	return box_cnt;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || visit[i][j] == 1)continue;
			board[i][j] = cnt;
			group[cnt] = bfs(i, j, cnt);
			cnt++;
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				answer = max(answer, check(i, j));
				
			}
		}
	}
	cout << answer;

}



