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

int n, m;
int board[31][31];
int last_answer = 0;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m-2; i++) {
		for (int j = i + 1; j < m-1; j++) {
			for (int k = j + 1; k < m; k++) {
				
				int answer = 0;
				for (int s = 0; s < n; s++) {
					answer += max(board[s][i], max(board[s][j], board[s][k]));
				}
				last_answer = max(answer, last_answer);
			}
		}
	}
	cout << last_answer;
}