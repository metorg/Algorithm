#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int visit[21];
int n, num;
vector<int> pleasure;
vector<int> tired;
int answer = 0;

void dfs(int pleasure_sum, int tired_sum,int cur) {
	if (tired_sum < 1)return;
	answer = max(pleasure_sum, answer);

	for (int i = cur; i < pleasure.size(); i++) {
		dfs(pleasure_sum + pleasure[i], tired_sum - tired[i], i + 1);
	}
}
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		tired.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		pleasure.push_back(num);
	}

	dfs(0,100,0);

	cout << answer;

	
}
