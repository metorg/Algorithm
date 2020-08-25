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

vector<int> v;

void dfs() {
	if (v.size() == b) {
		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';

		}
		cout << '\n';
		return;
	}
	for (int i = 1;i <= a;i++) {
		v.push_back(i);
		dfs();
		v.pop_back();

	}
}
int main() {
	cin >> a >> b;
	dfs();
}