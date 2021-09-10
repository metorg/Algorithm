#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int n;
int board[21][21];
int no_road[21][21];

void floydWarshall() {
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i == k)continue;
			for (int j = 0; j < n; j++) {
				if (i == j || j == k)continue;
				if (board[i][k] + board[k][j] < board[i][j]) {
					cout << -1;
					exit(0);
				}
				if (board[i][j] == board[i][k] + board[k][j])
					no_road[i][j] = 1;

			}
		}
	}
}

int main()
{

	ios::sync_with_stdio(0);

	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	floydWarshall();

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (no_road[i][j] == 0) {
				answer += board[i][j];
			}
		}
	}
	cout << answer / 2;
}
