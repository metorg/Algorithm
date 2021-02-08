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

int board[50][50];
int board2[50][50];

vector<pair<int, int>> aircleaner;

int n, m, t;
int flag;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };

void spread(int x, int y) {
	flag = 0;

	for (int i = 0;i < 4;i++) {
		int c_x = x + xx[i];
		int c_y = y + yy[i];
		if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m||board[c_x][c_y]==-1)continue;
		board2[c_x][c_y] += (board[x][y] / 5);
		flag++;
	}
	

}
void cleaner() {
	
		//위에 공기청정기 (반시계방향)
		for (int i = aircleaner[0].first-2;i >= 0;i--)board2[i+1][0] = board2[i][0];
		for (int i = 1;i < m;i++) board2[0][i - 1] = board2[0][i];
		for (int i = 1;i <= aircleaner[0].first;i++)board2[i - 1][m - 1] = board2[i][m - 1];
		for (int i = m - 2;i >= 0;i--)board2[aircleaner[0].first][i + 1] = board2[aircleaner[0].first][i];
	
		//밑에 공기청정기 (시계방향)
		for (int i = aircleaner[1].first + 2;i < n;i++)board2[i - 1][0] = board2[i][0];
		for (int i = 1;i < m;i++) board2[n - 1][i - 1] = board2[n - 1][i];
		for (int i = n - 1;i > aircleaner[1].first;i--)board2[i][m - 1] = board2[i - 1][m - 1];
		for (int i = m - 2;i >= 0;i--)board2[aircleaner[1].first][i + 1] = board2[aircleaner[1].first][i];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> t;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				aircleaner.push_back({ i,j });

			}
		}
	}
	while (t--) {
		
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (board[i][j] == 0 || board[i][j] == -1)continue;
				spread(i, j);
				board2[i][j] += board[i][j] - ((board[i][j] / 5) * flag);

			}
		}
		cleaner();
		memcpy(board,board2, sizeof(board));
		memset(board2, 0, sizeof(board2));

		board[aircleaner[0].first][aircleaner[0].second] = -1;
		board[aircleaner[1].first][aircleaner[1].second] = -1;
		
	}
	int answer = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			answer += board[i][j];

		}
	}
	cout << answer + 2;

}

