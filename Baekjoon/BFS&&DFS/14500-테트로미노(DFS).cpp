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


int n, m, num;
int board[501][501];
int visit[501][501];
int ans = 0;

void ex_case(int i, int j, int sum) {//'ㅗ' 모양일때
	if (i - 1 < 0 || j + 1 >= m || j - 1 < 0) {}
	else ans = max(ans, sum + board[i - 1][j] + board[i][j + 1] + board[i][j - 1]);//'ㅓ' 일때
	if (i - 1 < 0 || i + 1 >= n || j + 1 >= m) {}
	else ans = max(ans, sum + board[i - 1][j] + board[i + 1][j] + board[i][j + 1]);//'ㅗ' 일때
	if (i - 1 < 0 || i + 1 >= n || j - 1 < 0) {}
	else ans = max(ans, sum + board[i - 1][j] + board[i + 1][j] + board[i][j - 1]);//'ㅜ' 일때
	if (i + 1 >= n || j + 1 >= m || j - 1 < 0) {}
	else ans = max(ans, sum + board[i + 1][j] + board[i][j + 1] + board[i][j - 1]);//'ㅏ' 일때
}

void dfs(int i, int j, int depth, int sum) {
	if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j] == 1)return;
	sum = sum + board[i][j];
	if (depth == 4) {
		ans = max(sum, ans);
		return;
	}
	visit[i][j] = 1;
	dfs(i + 1, j, depth + 1, sum);
	dfs(i, j + 1, depth + 1, sum);
	dfs(i - 1, j, depth + 1, sum);
	dfs(i, j - 1, depth + 1, sum);
	visit[i][j] = 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			dfs(i, j, 1, 0);
			ex_case(i, j, board[i][j]);
		}
	}
	cout << ans;
}