#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
int num;
int num2;
int cnt = 0;
int sum = 0;
int sum2 = 0;
int answer[12] = {};
int visit[10000] = { 0, };
vector<int> v;
void dfs(int start, int depth) {

	for (int i = 0;i < depth;i++) {
		//cout << answer[i] << ' ';

		sum = (sum * 10) + answer[i];
		sum2 += answer[i];
	}

	if (sum2 == num2 && depth) {
		v.push_back(sum);

	}

	sum = 0;
	sum2 = 0;
	for (int i = start;i < num2;i++) {
		for (int j = 1;j <= 3;j++) {

			answer[depth] = j;

			dfs(i + 1, depth + 1);
		}

	}
}
int main() {



	cin >> num;

	for (int i = 0;i < num;i++) {
		cin >> num2;
		dfs(0, 0);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		cout << v.size();
		cout << '\n';
		v.clear();
	}
}

