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

void dfs() {
	if (v.size() == b) {
		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';

		}
		cout << '\n';
		return;
	}
	for (int i = 0;i < num.size();i++) {

		if (v.empty()) {
			v.push_back(num[i]);

			dfs();
			v.pop_back();

		}
		else if (v[v.size() - 1] <= num[i]) {
			v.push_back(num[i]);

			dfs();
			v.pop_back();

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
	num.erase(unique(num.begin(), num.end()), num.end());
	dfs();
}