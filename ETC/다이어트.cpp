#include <iostream>
#include <vector> 
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>

int total, N, K;
int num2;
using namespace std;

vector<int> v;
vector<int> v2;
int solve(vector<int> v, vector<int> v2) {
	int sum = 0;
	int max = 0;

	for (int i = 0;i < K;i++) {
		sum = v[i] + v2[K - i - 1];
		if (max < sum) {
			max = sum;
		}
	}
	return max;
}
int main() {
	int total;
	cin >> total;
	for (int i = 0;i < total;i++) {
		cin >> N >> K;
		for (int j = 0;j < N;j++) {
			cin >> num2;
			v.push_back(num2);
		}
		for (int k = 0;k < N;k++) {
			cin >> num2;
			v2.push_back(num2);
		}
		sort(v.begin(), v.end());
		sort(v2.begin(), v2.end());

		cout << "Case #" << i + 1 << '\n';
		cout << solve(v, v2) << '\n';
		v.clear();
		v2.clear();
	}
}

