#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
int num;
int num2;
int cnt = 0;
long long sum = 0;
int sum2 = 0;
long long answer[12] = {};
int visit[10000] = { 0, };
vector<long long> v;
void dfs(int start, int depth) {

	for (int i = 0;i < depth;i++) {

		sum = (sum * 10) + answer[i];
		sum2 += answer[i];
	}
	for (int i = 0; i < num - depth;i++)
	{
		sum *= 10;
	}

	if (sum2 == num && depth) {
		v.push_back(sum);

	}

	sum = 0;
	sum2 = 0;
	for (int i = start;i < num;i++) {
		for (int j = 1;j <= 3;j++) {

			answer[depth] = j;

			dfs(i + 1, depth + 1);
		}

	}
}
int main() {



	cin >> num >> num2;
	long long ten = 1;

	for (int j = 0; j < num; j++) ten *= 10;
	dfs(0, 0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (num2 > v.size()) {

		cout << -1;
		return 0;
	}
	int i, j;
	for (i = 0; i <= num;i++) {
		if ((v[num2 - 1] / ten) > 0)
		{
			cout << v[num2 - 1] / ten;
			v[num2 - 1] %= ten;
			break;
		}
		ten /= 10;
	}

	for (j = i - 1; j < num;j++) {
		if ((v[num2 - 1] / ten) > 0)
		{
			cout << '+' << v[num2 - 1] / ten;
			v[num2 - 1] %= ten;

		}
		ten /= 10;
	}


}

