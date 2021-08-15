#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> answer;
int v[101];
int visit[101];
int n;
int num;
int cut;
void dfs(int target,int start) {
	if (visit[start] == 1)return;
	if (start == target) {
		cut++;
		return;
	}
	
	visit[start] = 1;
	answer.push_back(start);
	dfs(target, v[start]);
	if (cut > 0) {

	}
	else {
		visit[start] = 0;
		answer.pop_back();
	}
	return;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i] == i) {
			visit[i] = 1;
			answer.push_back(i);
		}
		
	}
	for (int i = 1; i <= n; i++) {
		cut = 0;
		dfs(i, v[i]);
		if (cut > 0)answer.push_back(i);
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	
	

}