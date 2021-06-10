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
vector<string> v2;

void dfs() {
	if (v.size() == b) {
		string d = "";
		for (int i = 0;i < v.size();i++) {
			d += v[i] + '0';
		}

		v2.push_back(d);
		return;
	}


	for (int i = 0;i < num.size();i++) {
		v.push_back(num[i]);
		dfs();
		v.pop_back();

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
	dfs();
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (int i = 0;i < v2.size();i++) {
		for (int j = 0;j < v2[i].size();j++) {
			cout << v2[i][j] - '0' << ' ';
		}
		cout << '\n';
	}
}