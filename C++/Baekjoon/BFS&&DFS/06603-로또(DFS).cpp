#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
int num;
int answer[14] = {};
void dfs(int start, int depth,vector<int> v) {
	if (depth == 6) {
		for (int i = 0;i < 6;i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}
	for (int i = start;i < num;i++) {
		answer[depth] = v[i];
		dfs(i + 1, depth + 1, v);
	}
}
int main() {
	vector<int> v;
	
	int num2;
	while (1) {
		v.clear();
		cin >> num;
		if (num == 0)break;
		for (int i = 0;i < num;i++) {
			cin >> num2;
			v.push_back(num2);
		}
		dfs(0, 0,v);
		cout << '\n';
	}

}