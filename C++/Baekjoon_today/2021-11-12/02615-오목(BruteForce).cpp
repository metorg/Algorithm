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

int board[19][19];
int xx[4] = { 0,1,1,-1};
int yy[4] = { 1,0,1,1};
int xxx[4] = {0,-1,-1,1};
int yyy[4] = {-1,0,-1,-1};
int cut;

int search(int x, int y, int direction, int sum) {
	if (sum == 5) {
		cut = 1;
	}
	else if (sum > 5) {
		cut = 0;
	}

	int c_x = x + xx[direction];
	int c_y = y + yy[direction];
	if (c_x < 0 || c_y < 0 || c_x >= 19 || c_y >= 19 || board[c_x][c_y] != board[x][y])return 0;
	search(c_x, c_y, direction, sum + 1);

	if (cut == 1)return 5;
	else return 0;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					int c_x = i + xx[k];
					int c_y = j + yy[k];
					cut = 0;
					if (c_x < 0 || c_y < 0 || c_x >= 19 || c_y >= 19 || board[c_x][c_y] != board[i][j])continue;
					if (search(c_x, c_y, k, 2) == 5) {
						if (board[i + xxx[k]][j + yyy[k]] == board[c_x][c_y])continue;
						else {
							cout << board[i][j] << '\n';
							cout << i + 1 << ' ' << j + 1;
							return 0;
						}
					}
				}
				
			}
		}
	}
	cout << 0;
	return 0;
}