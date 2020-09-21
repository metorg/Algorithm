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
int top[100001];
int check[100001];
int visit[100001];
int nt;
int cnt;

void dfs(int cur) {
	visit[cur] = 1;
	nt = top[cur];
	if (!visit[nt])dfs(nt);
	else if (!check[nt]) {
		for (int i = nt;i != cur;i = top[i]) {
			cnt++;
		}
		cnt++;
	}
	check[cur] = 1;


}
int main() {
	int num;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> m;

		for (int j = 1;j <= m;j++) {
			cin >> top[j];
		}
		cnt = 0;
		for (int j = 1;j <= m;j++) {

			if (!visit[j]) {
				dfs(j);
			}
		}
		cout << m - cnt << '\n';

		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
	}
}