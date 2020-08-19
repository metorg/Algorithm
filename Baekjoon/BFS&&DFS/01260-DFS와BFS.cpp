#include <iostream>
#include <vector> 
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
using namespace std;

int a, b, c;
int visit[1001] = { 0, };
int line[1001][1001] = { 0, };
queue<int> q;
void bfs(int num) {
	q.push(num);
	int d;
	while (1) {
		if (q.empty())return;
		d = q.front();
		q.pop();
		cout << d << ' ';
		for (int i = 1;i <= a;i++) {
			if (line[d][i] == 1 && !visit[i]) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}

}
void dfs(int num) {
	cout << num << ' ';
	visit[num] = 1;
	for (int i = 1;i <= a;i++) {
		if (!visit[i] && line[num][i] == 1) {
			dfs(i);
		}
	}

}


int main() {
	int num, num2;
	cin >> a >> b >> c;
	for (int i = 0;i < b;i++) {
		cin >> num >> num2;
		line[num][num2] = 1;
		line[num2][num] = 1;
	}

	dfs(c);
	memset(visit, 0, sizeof(visit));
	cout << '\n';
	visit[c] = 1;
	bfs(c);
}