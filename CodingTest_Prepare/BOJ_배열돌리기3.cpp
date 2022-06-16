#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>

//배열 크기 101로 지정시 out of bounds 에러 이유를 모르겠음 
using namespace std;

int board[201][201];
int N, M, K;
int num;

void change() {
	int tmp;
	tmp = N;
	N = M;
	M = tmp;
}

void up_down(){
	int c_board[201][201];
	for (int i = N - 1,s=0; i >= 0; i--,s++) {
		for (int j = 0; j < M; j++) {
			c_board[s][j] = board[i][j];
		}
	}	
	memcpy(board, c_board, sizeof(c_board));
}
void right_rotation() {
	int c_board[201][201];
	change();
	for (int i = N-1, s = 0;  i>=0; i--, s++) {
		for (int j = M-1,k=0; j >=0; j--,k++) {
			c_board[s][k] = board[j][s];
		}
	}
	
	memcpy(board, c_board, sizeof(c_board));
}
void left_rotation() {
	int c_board[201][201];
	change();
	for (int i = N - 1, s = 0; i >= 0; i--, s++) {
		for (int j = 0; j <M; j++) {
			c_board[s][j] = board[j][i];
		}
	}

	memcpy(board, c_board, sizeof(c_board));
}
void left_right() {
	int c_board[201][201];
	for (int i = 0; i < N; i++) {
		for (int j = M - 1, s = 0; j >= 0; j--, s++) {
			c_board[i][s] = board[i][j];
		}
	}
	memcpy(board, c_board, sizeof(c_board));
}
void quater_right() {
	int c_board[201][201];
	for (int i = 0,s=N/2; i < N / 2;s++,i++) {
		for (int j = 0; j < M / 2; j++) {
			c_board[i][j] = board[s][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = M / 2, k = 0; j < M;k++, j++) {
			c_board[i][j] = board[i][k];
		}
	}
	for (int i = N/2,s=0; i < N;s++, i++) {
		for (int j = M/2; j < M; j++) {
			c_board[i][j] = board[s][j];
		}
	}
	for (int i = N / 2; i < N; i++) {
		for (int j = 0,s=M/2; j < M / 2;s++ ,j++) {
			c_board[i][j] = board[i][s];
		}
	}
	memcpy(board, c_board, sizeof(c_board));
}
void quater_left() {
	int c_board[201][201];
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0,k=M/2; j < M / 2;k++ ,j++) {
			c_board[i][j] = board[i][k];
		}
	}
	for (int i = 0,s=N/2; i < N;s++, i++) {
		for (int j = M / 2; j < M; j++) {
			c_board[i][j] = board[s][j];
		}
	}
	for (int i = N / 2; i < N; i++) {
		for (int j = M / 2,k=0; j < M;k++, j++) {
			c_board[i][j] = board[i][k];
		}
	}
	for (int i = N / 2, s = 0; i < N;s++, i++) {
		for (int j = 0 ; j < M / 2;  j++) {
			c_board[i][j] = board[s][j];
		}
	}
	memcpy(board, c_board, sizeof(c_board));
}
int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 1) {
			up_down();
		}
		else if (num == 2) {
			left_right();
		}
		else if (num == 3) {
			right_rotation();
		}
		else if (num == 4) {
			left_rotation();
		}
		else if (num == 5) {
			quater_right();
		}
		else if (num == 6) {
			quater_left();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j]<<' ';
		}
		cout << '\n';
	}
	
}
