#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;
int n, num, target;



string bfs(int num, int target) {
	int visit[10001] = {};
	string answer;
	queue<pair<int, string>> q;
	q.push({ num,answer });


	while (!q.empty()) {

		int x = q.front().first;
		string ch = q.front().second;

		q.pop();
		if (x == target)return ch;
		//"S"老锭
		if (visit[(x + 9999) % 10000] == 0) {
			q.push({ (x + 9999) % 10000, ch + 'S' });
		}

		if (x != 0) {
			//"D"老锭
			if (visit[(x * 2) % 10000] == 0) {
				q.push({ ((x * 2) % 10000),ch + 'D' });
				visit[((x * 2) % 10000)] = 1;
			}
			//"L"老锭
			if (visit[((x % 1000) * 10) + (x / 1000)] == 0) {
				q.push({ ((x % 1000) * 10) + (x / 1000),ch + 'L' });
				visit[((x % 1000) * 10) + (x / 1000)] = 1;
			}
			//"R"老锭
			if (visit[(x / 10) + ((x % 10) * 1000)] == 0) {
				q.push({ ((x / 10) + ((x % 10) * 1000)),ch + 'R' });
				visit[((x / 10) + ((x % 10) * 1000))] = 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num >> target;
		cout << bfs(num, target) << '\n';
	}
}