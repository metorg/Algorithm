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
int n, m, r, x;
vector<pair<int, int>> d;
vector<int> answer;
vector<vector<int>> d2(300001);
int visit[300000];
int visit2[1000000];
void bfs(int i) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ i,cnt });
	visit[i] = 1;
	while (!q.empty()) {
		int start = q.front().first;
		int k = q.front().second;
		q.pop();
		if (k >= r)break;
		for (int i = 0;i < d2[start].size();i++) {
			if (!visit[d2[start][i]]) {
				int c_k = k;
				c_k++;
				q.push({ d2[start][i],c_k });
				visit[d2[start][i]] = 1;
				if (c_k == r) {
					answer.push_back(d2[start][i]);
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.size() == 0) {
		cout << -1;
	}

	else {
		for (int i = 0;i < answer.size();i++) {
			cout << answer[i] << '\n';
		}
	}
}
int main() {
	cin >> n >> m >> r >> x;
	int a, b;

	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		d2[a].push_back(b);


	}
	bfs(x);
}


