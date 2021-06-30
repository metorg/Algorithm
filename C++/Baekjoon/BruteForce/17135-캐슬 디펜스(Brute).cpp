#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include<cstring>
#include<stack>

using namespace std;

int board[15][15];
int c_board[15][15];

vector<int> v;

int n, m, dist;

int brute_force() {
	
	vector<pair<int, int>> target;
	int answer = 0;
	int col = n+1;
	int line = 0;
	
	while (1) {

		col--;
		if (col == -1)break;

		for (int i = 0; i < v.size(); i++) {

			int limit = dist;
			int c_col = col;
			int target_x = 99;
			int target_y = 99;

			while (1) {
				c_col--;
				if (c_col == -1)break;
				for (int j = 0; j < m; j++) {
					if (c_board[c_col][j] == 1) {
						int r = abs(n-line - c_col) + abs(v[i] - j);
						
						if (limit > r) {
							limit = r;
							target_x = c_col;
							target_y = j;
						}
						else if (limit == r&&target_y>j) {
							target_x = c_col;
							target_y = j;
						}
					}
				}
			}
			
			if (target_x == 99 || target_y == 99)continue;
			else target.push_back({ target_x,target_y });						
		}
		for (int p = 0; p < target.size(); p++) {
			if (c_board[target[p].first][target[p].second]) {
				answer++;
				c_board[target[p].first][target[p].second] = 0;
			}
		}
		target.clear();
		line++;
	}
	return answer;
	
}
int main(){
	int last = 0;
	cin >> n >> m >> dist;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < m-2; i++) {
		v.push_back(i);
		for (int j = i + 1; j < m-1; j++) {
			v.push_back(j);
			for (int k = j + 1; k < m; k++) {
				v.push_back(k);
				memcpy(c_board, board, sizeof(board));
				last=max(last,brute_force());
				v.pop_back();
			}
			v.pop_back();
		}
		v.pop_back();
	}
	cout << last;

}