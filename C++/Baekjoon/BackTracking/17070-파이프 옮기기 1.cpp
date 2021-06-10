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

void column_dfs(int i, int j);
void diagonal_dfs(int i, int j);
void row_dfs(int i, int j);
int n;

int board[17][17];

int cnt = 0;

void column_dfs(int i, int j) {
	if (i == n - 1 && j == n - 1) {
		cnt++;
		return;
	}
	if (i + 1 < n && j < n && board[i + 1][j] == 0) column_dfs(i + 1, j);
	if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] == 0 && board[i][j + 1] == 0 && board[i + 1][j] == 0) diagonal_dfs(i + 1, j + 1);

}
void diagonal_dfs(int i, int j) {
	if (i == n - 1 && j == n - 1) {
		cnt++;
		return;
	}

	if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] == 0 && board[i][j + 1] == 0 && board[i + 1][j] == 0) diagonal_dfs(i + 1, j + 1);
	if (i < n && j + 1 < n && board[i][j + 1] == 0) row_dfs(i, j + 1);
	if (i + 1 < n && j < n && board[i + 1][j] == 0) column_dfs(i + 1, j);

}
void row_dfs(int i, int j) {
	if (i == n - 1 && j == n - 1) {
		cnt++;
		return;
	}
	if (i < n && j + 1 < n && board[i][j + 1] == 0) row_dfs(i, j + 1);
	if (i + 1 < n && j + 1 < n && board[i + 1][j + 1] == 0 && board[i][j + 1] == 0 && board[i + 1][j] == 0) diagonal_dfs(i + 1, j + 1);


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

	row_dfs(0, 1);

	cout << cnt;

}



