#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <stack>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>

#define INF 2e9
#define MAX 1001

using namespace std;

vector<pair<int, int>> v[10001];

int n, num, num2, weight;
int visit[10001];
int check, line = 0;

void dfs(int start, int weight) {
	visit[start] = 1;
	if (line < weight) {
		line = weight;
		check = start;
	}
	for (int i = 0;i < v[start].size();i++) {
		if (visit[v[start][i].first])continue;
		dfs(v[start][i].first, weight + v[start][i].second);
	}

}
int main() {
	cin >> n;
	for (int i = 0;i < n - 1;i++) {
		cin >> num >> num2 >> weight;
		v[num].push_back({ num2,weight });
		v[num2].push_back({ num,weight });
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(check, 0);
	cout << line;
}


