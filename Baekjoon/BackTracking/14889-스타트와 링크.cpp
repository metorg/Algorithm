#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

int power[21][21];
int N;
int mmax = 202;
int visit[21] = { 0, };
int sum2 = 0;
int sum = 0;
int ccnt = 0;

using namespace std;
void max_change() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i] && visit[j]) {
				sum += power[i][j];
			}
			else if (!visit[i] && !visit[j]) {
				sum2 += power[i][j];
			}
		}
	}
	mmax = min(mmax, abs(sum - sum2));
}
void dfs(int depth, int cnt) {

	if (depth == N / 2) {
		sum = 0;
		sum2 = 0;
		max_change();
	}
	for (int i = depth;i < N;i++) {
		if (!visit[i] && i > cnt&& ccnt < N / 2) {
			visit[i] = 1;
			ccnt++;
			dfs(depth + 1, i);
			visit[i] = 0;
			ccnt--;
		}
	}
}
int main() {

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> power[i][j];
		}
	}
	int cnt = 0;
	dfs(0, -1);
	cout << mmax;

}