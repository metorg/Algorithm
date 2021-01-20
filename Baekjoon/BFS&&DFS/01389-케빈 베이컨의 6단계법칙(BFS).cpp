#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

vector<vector<int>> line(100 + 1);
int sum[101];


void bfs(int start, int cnt) {

	queue<pair<int, int>> q;
	bool visited[101] = { false };
	
	q.push({ start,cnt });
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < line[x].size();i++) {

			if (visited[line[x][i]])continue;

			visited[line[x][i]] = true;
			sum[start] += y + 1;
			q.push({ line[x][i],y + 1 });
		}
	}
	return;
}
int main()
{

	int n, m, num, num2;
	int user = 1;
	int answer = 100;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> num >> num2;
		line[num].push_back(num2);
		line[num2].push_back(num);
	}
	for (int i = 1;i <= n;i++) {
		bfs(i, 0);
	}
	for (int i = 1;i <= n;i++) {
		if (answer > sum[i]) {
			answer = sum[i];
			user = i;
		}
	}
	cout << user;
}