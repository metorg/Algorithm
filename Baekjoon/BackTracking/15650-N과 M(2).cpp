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
int cnt = 0;

int sum = 1;

void dfs() {

	if (v.size() == b) {
		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';

		}
		cout << '\n';
		cnt++;
		return;
	}
	for (int i = 1;i <= a;i++) {
		if (!visit[i]) {
			if (v.empty()) {
				v.push_back(i);
				visit[i] = 1;
				dfs();
				v.pop_back();
				visit[i] = 0;
			}
			else if (v[v.size() - 1] < i) {
				v.push_back(i);
				visit[i] = 1;
				dfs();
				v.pop_back();
				visit[i] = 0;
			}
		}
	}


}
int main() {
	cin >> a >> b;

	dfs();

}