#include <iostream>
#include <vector>

using namespace std;

char board[10001][10001];
int n;

void draw_star(int row,int col) {
	board[row][col] = '*';

	board[row + 1][col -1] = '*';
	board[row + 1][col + 1] = '*';

	for (int i = -2; i <=2 ; i++) {
		board[row + 2][col + i] = '*';
	}
}
void dfs(int len,int row ,int col) {

	if (len == 3) {
		draw_star(row, col);
		return;
	}

	dfs(len / 2, row, col);
	dfs(len / 2, row + len / 2, col - len / 2);
	dfs(len / 2, row + len / 2, col + len / 2);
}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n - 1; j++)
			board[i][j] = ' ';

	dfs(n, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << board[i][j];
		}
		cout<<'\n';
	}
}
