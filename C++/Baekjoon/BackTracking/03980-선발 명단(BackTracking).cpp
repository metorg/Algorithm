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

int board[11][11];
int n,answer;
int visit[11];

void backtracking(int depth,int sum) {
	if (depth == 11) {
		answer = max(answer, sum);
	}
	for (int i = 0; i < 11; i++) {
		if (board[depth][i] == 0||visit[i])continue;
		visit[i] = 1;
		backtracking(depth + 1, sum + board[depth][i]);
		visit[i] = 0;
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int k = 0; k < n; k++) {
		answer = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> board[i][j];
			}
		}
		backtracking(0, 0);
		cout << answer<<'\n';
		memset(visit, 0, sizeof(visit));
	}

}