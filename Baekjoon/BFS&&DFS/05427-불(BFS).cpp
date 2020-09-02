#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
///어려웠다 다시한번 봐야 할 문제 
using namespace std;

int visit[1002][1002];
int visit2[1002][1002] = { 0, };
int num;
int num2;
int mcnt = 210000000;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,1,-1 };
int cas = 0;
vector<pair<int, int>> fire;
void fire_bfs() {
	int cnt = 0;
	queue<pair<pair<int, int>, int>>q;
	for (int i = 0;i < fire.size();i++) {//불들초기 위치를 큐에 푸쉬
		visit[fire[i].first][fire[i].second] = cnt;
		visit2[fire[i].first][fire[i].second] = 1;
		cnt++;
		q.push({ { fire[i].first,fire[i].second }, cnt });
		cnt = 0;
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {//불들이 1초마다 위치미다 숫자로 .을 바꿈
			int x_c = x + xx[i];
			int y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= num2 || y_c >= num
				|| visit[x_c][y_c] == -1 || visit2[x_c][y_c] == 1) {

				continue;

			}
			int ccnt = k;
			ccnt++;
			q.push({ { x_c,y_c },ccnt });

			visit[x_c][y_c] = k; //방문 처리
			visit2[x_c][y_c] = 1;
		}
	}
}
void human_bfs(int i, int j) {
	int cnt = 0;
	queue<pair<pair<int, int>, int>>q;
	visit[i][j] = cnt + '0';
	visit2[i][j] = 1;
	cnt++;
	q.push({ { i,j},cnt });
	int t = 0;


	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x_c = x + xx[i];
			int y_c = y + yy[i];

			if (x_c < 0 || y_c < 0 || x_c >= num2 || y_c >= num
				|| visit[x_c][y_c] == -1 || visit[x_c][y_c] <= k || visit2[x_c][y_c] == 1) {//인간 경로가 더 짧을시만 나아갈수있음
				if (visit[x_c][y_c] == -4) {//불은 막혀있고 .으로 차있을때 인간은 빠져나가는 코드

					visit[x_c][y_c] = k; //방문 처리
					visit2[x_c][y_c] = 1;
					int ccnt = k;
					ccnt++;
					q.push({ { x_c,y_c },ccnt });
					t = 1;
				}
				else {
					continue;
				}
			}

			if (x_c == 0 || y_c == 0 || x_c == num2 - 1 || y_c == num - 1) {
				cas++;
				if (mcnt > k) {
					mcnt = k;
				}
			}


			else {
				if (t == 0) {
					visit[x_c][y_c] = k; //방문 처리
					visit2[x_c][y_c] = 1;
					int ccnt = k;
					ccnt++;
					q.push({ { x_c,y_c },ccnt });
				}
				t = 0;
			}

		}
	}

}

int main() {
	int a;
	int last, last2;
	char d;
	cin >> a;
	for (int n = 0;n < a;n++) {
		cin >> num >> num2;
		for (int i = 0;i < num2;i++) {
			for (int j = 0;j < num;j++) {
				cin >> d;
				if (d == '*') {
					visit[i][j] = -2;
					fire.push_back({ i,j });
				}
				else if (d == '@') {
					visit[i][j] = -3;
					last = i;
					last2 = j;
				}
				else if (d == '#') {
					visit[i][j] = -1;
				}
				if (d == '.') {
					visit[i][j] = -4;
				}
			}
		}
		if (last == 0 || last2 == 0 || last == num2 - 1 || last2 == num - 1) {//상근이가 제일 테두리에 있을경우 1출력후 넘어감
			cout << 1 << '\n';
			continue;

		}
		fire_bfs();
		cas = 0;
		mcnt = 210000000;

		memset(visit2, 0, sizeof(visit2));
		human_bfs(last, last2);//상근이 탈출 가능성과 거리


		if (cas >= 1 && mcnt != 210000000) {//테두리까지 도착했으면 cas는 1이상이고 mcnt에는 최소경로를 넣어줌
			cout << mcnt + 1 << '\n';
		}
		else
			cout << "IMPOSSIBLE" << '\n';
		fire.clear();
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
	}
}