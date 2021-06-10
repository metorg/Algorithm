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

using namespace std;

int a, b, c, d, e;
int br = 0;
int visit[1000001] = { 0, };

int bfs(int depth, int cnt) {
	queue<pair<int, int>> q;


	q.push({ depth, cnt });

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == c) {
			br++;
			return y;
		}
		if (!visit[x + d] && x + d <= c) {
			int k = y;
			k++;
			visit[x + d] = 1;
			q.push({ x + d,k });

		}
		else if (!visit[x - e] && x + d >= c) {
			int k = y;
			k++;
			visit[x - e] = 1;
			q.push({ x - e ,k });
		}
		else
			return 0;



	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int f;
	cin >> a >> b >> c >> d >> e;
	if (b == c) {
		cout << 0;
		return 0;
	}
	f = bfs(b, 0);
	if (br > 0) {
		cout << f;
	}
	else
		cout << "use the stairs";
}