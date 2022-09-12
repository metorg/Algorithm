#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct {
	int r;
	int c;
	int s;
}info;

int board[51][51];
int n, m, k;
int s, r, c;
int answer = 1e9;
int visit[7];
vector<info> v;

void move(int cur ,int depth ,int board[51][51]) {

	int c_board[51][51];
	memcpy(c_board, board, sizeof(int) * 51 * 51);

	int left_one = v[cur].r - v[cur].s - 1;
	int left_two = v[cur].c - v[cur].s - 1;
	int right_one = v[cur].r + v[cur].s - 1;
	int right_two = v[cur].c + v[cur].s - 1;
	int cnt = (right_one - left_one) / 2;

	for (int j = 0; j < cnt; j++) {
		int tmp = c_board[left_one][left_two];
		int tmp2;
		for (int k = left_two + 1; k <= right_two; k++) {
			tmp2 = c_board[left_one][k];
			c_board[left_one][k] = tmp;
			tmp = tmp2;
		}
		for (int k = left_one + 1; k <= right_one; k++) {
			tmp = c_board[k][right_two];
			c_board[k][right_two] = tmp2;
			tmp2 = tmp;
		}
		for (int k = right_two - 1; k >= left_two; k--) {
			tmp2 = c_board[right_one][k];
			c_board[right_one][k] = tmp;
			tmp = tmp2;
		}
		for (int k = right_one - 1; k >= left_one; k--) {
			tmp = c_board[k][left_two];
			c_board[k][left_two] = tmp2;
			tmp2 = tmp;
		}
		left_one++;
		left_two++;
		right_one--;
		right_two--;
	}
    
	if (depth == k) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += c_board[i][j];
			}
			answer = min(answer, sum);
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (visit[i] ==1)continue;
		visit[i] = 1;
		move(i,depth + 1, c_board);
		visit[i] = 0;
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
	for (int i = 0; i < k; i++) {
		visit[i] = 1;
		move(i,1, board);
		visit[i] = 0;
	}
	
	cout << answer;
}
