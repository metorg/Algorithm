#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;
int n, normal_cnt = 0, special_cnt =0 ;
char board[101][101];
int special_visit[101][101];
int normal_visit[101][101];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };

void normal_bfs(int i ,int j,char target){//일반 전용
	queue<pair<int, int>> q;
	q.push({ i,j });
	normal_visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x_c = xx[i] + x;
			int y_c = yy[i] + y;
			if (x_c < 0 || y_c < 0 || x_c >= n || y_c >= n || board[x_c][y_c] != target||normal_visit[x_c][y_c]==1)continue;
			if (target == 'G')board[x_c][y_c] = 'R';
			q.push({ x_c,y_c });
			normal_visit[x_c][y_c] = 1;
		}
	}
}

void special_bfs(int i,int j,char target) {//적록색약 전용
	queue<pair<int, int>> q;
	q.push({ i,j });
	special_visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x_c = xx[i] + x;
			int y_c = yy[i] + y;
			if (x_c < 0 || y_c < 0 || x_c >= n || y_c >= n || board[x_c][y_c] != target || special_visit[x_c][y_c] == 1)continue;
			q.push({ x_c,y_c });
			special_visit[x_c][y_c] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (normal_visit[i][j])continue;
			normal_bfs(i, j, board[i][j]);
			normal_cnt++;
			if (board[i][j] == 'G')board[i][j] = 'R';
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (special_visit[i][j])continue;
			special_bfs(i, j, board[i][j]);
			special_cnt++;
		}
	}
	cout << normal_cnt << ' ' << special_cnt;
}