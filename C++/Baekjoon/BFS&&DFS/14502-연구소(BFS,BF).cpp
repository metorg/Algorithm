#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stack>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

int board[8][8];
int visit[8][8];
int room_visit[64];
int n, m;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };
int answer = 0;
int wall_cnt=0;

vector<pair<int, int>> room;
vector<pair<int, int>> bug;

void bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0;i < bug.size();i++) {
		q.push({ bug[i].first,bug[i].second });
		visit[bug[i].first][bug[i].second] = 1;
		
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || visit[c_x][c_y] == 1 || board[c_x][c_y] == 1)continue;
			q.push({ c_x,c_y });
			visit[c_x][c_y] = 1;
			cnt++;
		}
	}
	
	answer = max(answer, wall_cnt - 3 - cnt);

}
void wall_install(int cnt) {
	if (cnt == 3) {
		memset(visit, 0, sizeof(visit));
		bfs();
		return;

	}
	for (int i = 0;i < room.size();i++) {
		if (room_visit[i] == 1)continue;
		room_visit[i] = 1;
		board[room[i].first][room[i].second] = 1;
		wall_install(cnt + 1);
		board[room[i].first][room[i].second] = 0;
		room_visit[i] = 0;
	}
	
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				room.push_back({ i,j });
				wall_cnt++;
			}
			else if (board[i][j] == 2) {
				bug.push_back({ i,j });
			}
		}
	}
	for (int i = 0;i < room.size();i++) {
		room_visit[i] = 1;
		board[room[i].first][room[i].second] = 1;
		wall_install(1);
		board[room[i].first][room[i].second] = 0;
	}
	cout << answer;
}



