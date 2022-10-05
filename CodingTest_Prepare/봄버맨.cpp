#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int n, m,t;
char board[210][210];
vector<pair<int, int>> v;

void dfs(int depth) {
	if (depth == t) return;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'O')v.push_back({ i,j });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = 'O';
		}
	}
	for (int i = 0; i < v.size(); i++) {
		board[v[i].first][v[i].second] = '.';
		for (int j = 0; j < 4; j++) {
			int c_x = v[i].first + xx[j];
			int c_y = v[i].second + yy[j];
			if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= m)continue;
			board[c_x][c_y] = '.';
		}
	}
	v.clear();
	dfs(depth + 2);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	if (t % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << 'O';
			}
			cout << '\n';
		}
	}
	else {
		dfs(1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
	}
}
