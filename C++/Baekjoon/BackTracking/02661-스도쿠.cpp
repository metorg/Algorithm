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
#include<set>
using namespace std;

int board[10][10];
int col_visit[10][10];
int row_visit[10][10];
int square_visit[10][10];
vector<pair<int, int>> zero;
int cut = 0;

void sudoku(int depth) {
	if (depth == zero.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int j = 1; j <= 9; j++) {
		if (row_visit[zero[depth].first][j] || col_visit[j][zero[depth].second] || square_visit[((zero[depth].first - 1) / 3) * 3 + ((zero[depth].second - 1) / 3)][j])continue;
		row_visit[zero[depth].first][j] = 1;
		col_visit[j][zero[depth].second] = 1;
		square_visit[((zero[depth].first - 1) / 3) * 3 + ((zero[depth].second - 1) / 3)][j] = 1;
		board[zero[depth].first][zero[depth].second] = j;
		sudoku(depth + 1);
		row_visit[zero[depth].first][j] = 0;
		col_visit[j][zero[depth].second] = 0;
		square_visit[((zero[depth].first - 1) / 3) * 3 + ((zero[depth].second - 1) / 3)][j] = 0;
		board[zero[depth].first][zero[depth].second] = 0;
	}


}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)zero.push_back({ i,j });
			else {
				row_visit[i][board[i][j]] = 1;
				col_visit[board[i][j]][j] = 1;
				square_visit[((i - 1) / 3) * 3 + ((j - 1) / 3)][board[i][j]] = 1;
			}
		}
	}
	sudoku(0);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

}