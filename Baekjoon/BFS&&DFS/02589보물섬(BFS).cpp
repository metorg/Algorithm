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
int n, m;
char board[51][51];
int visit[51][51];
int xx[4] = {-1,1,0,0};
int yy[4] = { 0,0,-1,1 };
int ccnt;
void bfs(int i,int j) {
	int cnt = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({{ i,j }, cnt});
	visit[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x_c = x + xx[i];
			int y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= n || y_c >= m || visit[x_c][y_c] == 1||board[x_c][y_c]=='W')continue;
			q.push({ { x_c,y_c }, k + 1 });
			visit[x_c][y_c] = 1;
			if ((k + 1) > ccnt) {
				ccnt = k + 1;
			}

		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
		}
	}
	ccnt = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (board[i][j] == 'L') {
				bfs(i,j);
				
				memset(visit, 0, sizeof(visit));
			}
		}
		
	}
	cout << ccnt;
}