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
vector<int> num;

void dfs(int depth) {
	if (v.size() == b) {
		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';

		}
		cout << '\n';
		return;
	}
	for (int i = 0;i < num.size();i++) {
		if (!visit[i]) {
			v.push_back(num[i]);
			visit[i] = 1;
			dfs(0);
			v.pop_back();
			visit[i] = 0;
		}

	}
}
int main() {
	cin >> a >> b;
	int num2;
	for (int i = 0;i < a;i++) {
		cin >> num2;
		num.push_back(num2);
	}
	sort(num.begin(), num.end());
	dfs(0);
}