#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

using namespace std;

int n;
int board[20][20];
int fish[10];
int xx[4] = { -1,0,1,0, };
int yy[4] = { 0,-1,0,1 };
int answer = 0;

void bfs(int i, int j, int eat, int size) {
	
	int remember_x = 22, remember_y = 22;
	int length_size = 1e9;
	int visit[20][20] = {};
	int flag = 0;
	queue<pair<pair<int, int>, int>> q;
	visit[i][j] = 1;

	q.push({ { i,j }, 0 });


	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int length = q.front().second;
		
		q.pop();
		flag = 0;

		if (length > length_size) {

			fish[board[remember_x][remember_y]] -= 1;
			board[remember_x][remember_y] = 0;
			eat += 1;
			
			if (size == eat) {
				size += 1;
				eat = 0;
			}
			
			while (!q.empty())q.pop();//bfs 모든 값들 초기화
			memset(visit, 0, sizeof(visit));
			q.push({ { remember_x,remember_y },0 });
			flag++;
			remember_x = 22;
			remember_y = 22;
			length_size = 1e9;
			int sum = 0;
			
			answer += length;//조건에 만족하는 거리의 값을 최종 값에 누적해서 더해준다.
			
			for (int i = 1;i < size;i++)//아기상어보다 더 작은 크기의 물고기가 없으면 종료한다
				sum += fish[i];
			if (sum == 0)return ;
		}

		if (flag == 0) {
			for (int i = 0;i < 4;i++) {
				int c_x = x + xx[i];
				int c_y = y + yy[i];
				if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n || visit[c_x][c_y] == 1 || size < board[c_x][c_y])continue;

				if (board[c_x][c_y] != 0 && size > board[c_x][c_y]) {//동일한 거리값을 가졌을때 더빠른 행,열 처리
					length_size = length;
					if (remember_x > c_x) {
						remember_y = c_y;
						remember_x = c_x;
					}
					else if (remember_y == c_y) {
						if (remember_x > c_x) {
							remember_x = c_x;
						}
					}
				}
				q.push({ {c_x,c_y},length + 1 });

				visit[c_x][c_y] = 1;
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int start, start2;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				fish[board[i][j]]++;
			}
			if (board[i][j] == 9) {
				start = i;
				start2 = j;
				board[i][j] = 0;
			}
		}
	}
	bfs(start, start2, 0, 2);
	cout << answer;
}
