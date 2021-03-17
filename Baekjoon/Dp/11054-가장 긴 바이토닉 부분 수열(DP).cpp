#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>
#include<string>


using namespace std;

int n, num;
int left_dp[1000];
int right_dp[1000];
vector<int> v;
int answer = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);

		for (int j = 0; j <= i; j++) {
			if (v[i] > v[j]) left_dp[i] = max(left_dp[i], left_dp[j]);
		}
		left_dp[i] += 1;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = v.size() - 1; j >= 0; j--) {
			if (v[i] > v[j]) right_dp[i] = max(right_dp[i], right_dp[j]);
		}
		right_dp[i] += 1;
	}
	for (int i = 0; i < n; i++) {
		answer=max(left_dp[i] + right_dp[i], answer);
	}
	cout << answer-1;
	
}