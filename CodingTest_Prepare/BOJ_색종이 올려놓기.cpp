#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int n, m1, m2;
int dp[101];

int answer = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m1 >> m2;
		if (m1 > m2)v.push_back({ m1,m2 });
		else v.push_back({ m2,m1 });
		
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].first >= v[j].first && v[i].second >= v[j].second) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
		answer = max(answer, dp[i]);
	}

	cout << answer;
}
