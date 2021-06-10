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
#include<set>

using namespace std;

int v, c_v;
int new_start,num,num2;
int line=0;
int visit[100001];
vector<pair<int,int>> root[100001];

void dfs(int start,int weight) {
	visit[start] = 1;
	if (line < weight) {
		line = weight;
		new_start = start;
	}
	for (int i = 0;i < root[start].size();i++) {
		if (visit[root[start][i].first] == 1)continue;
		dfs(root[start][i].first, weight + root[start][i].second);
	}
}
int main() {

	ios::sync_with_stdio(0);
	
	cin >> v;

	for (int i = 0;i < v;i++) {
		cin >> c_v;
		while (1) {
			cin >> num;
			if (num == -1)break;
			cin >> num2;
			root[c_v].push_back({ num,num2 });
			root[num].push_back({ c_v,num2 });
		}
	}

	dfs(1,0);
	line = 0;
	memset(visit, 0, sizeof(visit));
	dfs(new_start, 0);
	
	cout << line;
}