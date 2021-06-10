#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>

using namespace std;
int a, b;
int visit[9] = { 0, };
vector<int> v;

void dfs(int depth) {
	if (v.size() == b) {
		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';

		}
		cout << '\n';
		return;
	}
	for (int i = 1;i <= a;i++) {
		if (!visit[i]) {
			v.push_back(i);
			visit[i] = 1;
			dfs(0);
			v.pop_back();
			visit[i] = 0;
		}

	}
}
int main() {
	cin >> a >> b;
	dfs(0);
}