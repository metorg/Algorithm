#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int visit[9];
vector<string> v;
string s;
long long tmp = 1e17;

void dfs(int depth, string s) {
	if (depth == n) {
		if (stoull(s) < tmp) {
			tmp = stoull(s);
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (visit[i])continue;
		visit[i] = 1;
		if (s[s.length() - 1] == v[i][0])dfs(depth + 1, s + v[i][1]);
		else dfs(depth + 1, s + v[i]);
		visit[i] = 0;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	dfs(0, "0");
	cout << tmp;

	return 0;
}
