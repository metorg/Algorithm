#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int n = 9;
int board[10][10];//��������
int visit[10][10] = { 0, };//���ߺ��� üũ�ϴ� �湮����
int visit2[10][10] = { 0, };//���ߺ��� üũ�ϴ� �湮����
int Square[10][10] = { 0, };//������ǥ�� 9ĭ�� �ɰ��� üũ�ϴ� �湮����
vector<pair<int, int>> v;//0�� ������ �����ϴ� ����

void dfs(int depth) {
	if (depth == v.size()) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				cout << board[i][j] << ' ';

			}
			cout << '\n';
		}
		exit(0);
	};
	for (int i = 1;i <= n;i++) {
		if (!visit[v[depth].first][i] && !visit2[i][v[depth].second] && (!Square[((v[depth].first - 1) / 3) * 3 + ((v[depth].second - 1) / 3)][i])) {
			visit[v[depth].first][i] = 1;
			visit2[i][v[depth].second] = 1;
			Square[((v[depth].first - 1) / 3) * 3 + ((v[depth].second - 1) / 3)][i] = 1;
			board[v[depth].first][v[depth].second] = i;
			dfs(depth + 1);
			visit[v[depth].first][i] = 0;
			visit2[i][v[depth].second] = 0;
			Square[((v[depth].first - 1) / 3) * 3 + ((v[depth].second - 1) / 3)][i] = 0;

		}
	}
}

int main() {

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				v.push_back({ i,j });
			}
			else {
				visit[i][board[i][j]] = 1;
				visit2[board[i][j]][j] = 1;
				Square[((i - 1) / 3) * 3 + ((j - 1) / 3)][board[i][j]] = 1;
			}
		}
	}
	dfs(0);

}