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
int n;
int p_i, c_i;
int cnt2 = 0;
vector<pair<int, int>> v;
vector<int> up;
int main() {
	cin >> n;
	int cnt = 0;
	int answer = 0;
	int answer2 = 0;
	for (int i = 0;i < n;i++) {
		cin >> p_i >> c_i;
		v.push_back({ c_i,p_i });
	}
	sort(v.begin(), v.end());

	if (v[0].first < v[0].second) {
		cout << -1;
		return 0;
	}
	else {
		answer = v[0].second;
		answer2 = v[0].second;
	}
	for (int i = 1;i < v.size();i++) {
		int sum = v[i].first - v[i - 1].first;
		answer += v[i].second;
		if (cnt2 == 0) {
			answer2 += v[i].second;
		}
		if (answer > v[i].first) {

			cout << -1;
			return 0;
		}
		if (answer2 > v[0].second&& cnt2 == 0) {
			answer2 -= v[i].second;
			cnt2++;
		}
		if (sum < v[i].second) {
			cnt++;

		}
	}
	answer2 = v[0].first - answer2;
	int cnt2 = 0;
	for (int i = answer2;i >= 0;i--) {
		int sum2 = i;
		int t = 0;
		for (int j = 0;j < v.size();j++) {
			sum2 += v[j].second;
			if (sum2 > v[j].first) {
				cnt2++;
				t++;
				break;
			}
		}
		if (t == 0) {
			up.push_back(i);
		}
	}
	sort(up.begin(), up.end());
	if (cnt2 == answer2 + 1) {
		cout << -1;

	}
	else {
		if (cnt < 0) {
			cout << v[0].first - v[0].second;
		}
		else {
			cout << up[up.size() - 1];
		}
	}
}