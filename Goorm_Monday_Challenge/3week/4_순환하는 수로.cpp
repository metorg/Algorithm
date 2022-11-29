#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[10001];
int visit[10001];
int n, num, num2;
vector<int> answer;
int cut = 0;

void dfs(int start, int end) {
	if (answer.size() >= 3 && start == end) {
		cut = 1;
		return;
	}

	for (int i = 0; i < v[start].size(); i++) {
		if (visit[v[start][i]] == 1)continue;
		answer.push_back(v[start][i]);
		visit[v[start][i]] = 1;
		dfs(v[start][i], end);
		if (cut == 1)break;
		visit[v[start][i]] = 0;
		answer.pop_back();
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num >> num2;
		v[num].push_back(num2);
		v[num2].push_back(num);
	}

	for (int i = 1; i <= n; i++) {
		dfs(i, i);
	}
	
	sort(answer.begin(),answer.end());
	
	cout<<answer.size()<<'\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}
