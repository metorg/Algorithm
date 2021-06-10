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
///������� �ٽ��ѹ� ���� �� ���� 
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
	for (int i = 0;i < fire.size();i++) {//�ҵ��ʱ� ��ġ�� ť�� Ǫ��
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

		for (int i = 0;i < 4;i++) {//�ҵ��� 1�ʸ��� ��ġ�̴� ���ڷ� .�� �ٲ�
			int x_c = x + xx[i];
			int y_c = y + yy[i];
			if (x_c < 0 || y_c < 0 || x_c >= num2 || y_c >= num
				|| visit[x_c][y_c] == -1 || visit2[x_c][y_c] == 1) {

				continue;

			}
			int ccnt = k;
			ccnt++;
			q.push({ { x_c,y_c },ccnt });

			visit[x_c][y_c] = k; //�湮 ó��
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
				|| visit[x_c][y_c] == -1 || visit[x_c][y_c] <= k || visit2[x_c][y_c] == 1) {//�ΰ� ��ΰ� �� ª���ø� ���ư�������
				if (visit[x_c][y_c] == -4) {//���� �����ְ� .���� �������� �ΰ��� ���������� �ڵ�

					visit[x_c][y_c] = k; //�湮 ó��
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
					visit[x_c][y_c] = k; //�湮 ó��
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
		if (last == 0 || last2 == 0 || last == num2 - 1 || last2 == num - 1) {//����̰� ���� �׵θ��� ������� 1����� �Ѿ
			cout << 1 << '\n';
			continue;

		}
		fire_bfs();
		cas = 0;
		mcnt = 210000000;

		memset(visit2, 0, sizeof(visit2));
		human_bfs(last, last2);//����� Ż�� ���ɼ��� �Ÿ�


		if (cas >= 1 && mcnt != 210000000) {//�׵θ����� ���������� cas�� 1�̻��̰� mcnt���� �ּҰ�θ� �־���
			cout << mcnt + 1 << '\n';
		}
		else
			cout << "IMPOSSIBLE" << '\n';
		fire.clear();
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
	}
}