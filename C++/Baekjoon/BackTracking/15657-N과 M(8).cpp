#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<set>
#define MAX 20010
#define INF 987654321
using namespace std;
int n, m,num;
vector<int> v;
vector<int> answer(1);

void dfs(int depth) {
	if (depth == m) {
		for (int i = 1;i < answer.size();i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0;i < v.size();i++) {
		if (answer[answer.size() - 1] > v[i])continue;
		answer.push_back(v[i]);
		
		dfs(depth + 1);	
		answer.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	dfs(0);
}

