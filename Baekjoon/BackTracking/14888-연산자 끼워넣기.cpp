#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;

int num;
int n, m;
int function[4] = { 0,0,0,0 };
int mmax = -2e9;
int mmin = 2e9;
vector<int> number;
void maxmin(int sum) {
	if (mmax < sum) {
		mmax = sum;
	}
	if (mmin > sum) {
		mmin = sum;
	}
}
void bfs() {
	int sum = number[0];
	queue<pair<pair<int, int>, int>> q;
	queue<pair<pair<int, int>, int>> q2;
	q.push({ { function[0],function[1] }, sum });
	q2.push({ { function[2],function[3] },1 });
	while (!q.empty()) {
		int plus = q.front().first.first;
		int minus = q.front().first.second;
		int c_sum = q.front().second;
		int	mul = q2.front().first.first;
		int div = q2.front().first.second;
		int size = q2.front().second;

		q.pop();
		q2.pop();
		if (size == number.size()) {
			maxmin(c_sum);
			continue;
		}
		for (int j = 0;j < 4;j++) {
			if (j == 0 && plus > 0) {
				int cc_sum = c_sum + number[size];
				q.push({ { plus - 1,minus },cc_sum });
				q2.push({ { mul,div },size + 1 });

			}
			else if (j == 1 && minus > 0) {
				int cc_sum = c_sum - number[size];
				q.push({ { plus,minus - 1 },cc_sum });
				q2.push({ { mul,div },size + 1 });

			}
			else if (j == 2 && mul > 0) {
				int cc_sum = c_sum * number[size];
				q.push({ { plus,minus },cc_sum });
				q2.push({ { mul - 1,div },size + 1 });

			}
			else if (j == 3 && div > 0) {
				int cc_sum = c_sum / number[size];

				q.push({ { plus,minus },cc_sum });
				q2.push({ { mul,div - 1 }, size + 1 });
			}
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> n;
		number.push_back(n);
	}
	for (int i = 0;i < 4;i++) {
		cin >> m;
		function[i] = m;
	}
	bfs();
	cout << mmax << '\n' << mmin;
}