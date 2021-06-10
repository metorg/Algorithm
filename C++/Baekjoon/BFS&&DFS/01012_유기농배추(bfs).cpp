#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;

int board[50][50];
vector<pair<int, int>> bug;
int visit[50][50];
int T;
int n, m, num;
int st, st2;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
void bfs(int start, int start2) {
	queue<pair<int, int>> q;
	q.push({ start,start2 });
	visit[start][start2] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c_x = x + xx[i];
			int c_y = y + yy[i];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m || visit[c_x][c_y] == 1 || board[c_x][c_y] == 0)continue;
			q.push({ c_x,c_y });
			visit[c_x][c_y] = 1;
		}
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		cin >> n >> m >> num;
		for (int j = 0; j < num; j++) {
			cin >> st >> st2;
			bug.push_back({ st,st2 });
			board[st][st2] = 1;
		}

		for (int j = 0; j < bug.size(); j++) {
			if (visit[bug[j].first][bug[j].second] == 0) {
				bfs(bug[j].first, bug[j].second);
				cnt++;
			}
		}
		cout << cnt << '\n';
		memset(visit, 0, sizeof(visit));
		memset(board, 0, sizeof(board));
		bug.clear();
	}
}
