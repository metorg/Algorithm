#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;
int n,num1,num2;

vector<vector<int>> v(100001);
int answer[100001];

int bfs(int start) {
	
	queue<int> q;
	q.push(start);
	answer[start] = 1;

	while (!q.empty()) {
		
		int num = q.front();	
		q.pop();

		for (int i = 0;i < v[num].size();i++) {
			int next = v[num][i];
			if (answer[next])continue;
			answer[next] = num;
			q.push(next);
		}
	}
	return 0;
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0;i < n-1;i++) {
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	bfs(1);
	for (int i = 2;i <= n;i++) {
		cout << answer[i] << '\n';
	}
}

