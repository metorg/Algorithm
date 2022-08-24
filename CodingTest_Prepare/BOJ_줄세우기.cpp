#include <iostream>
#include <vector>

using namespace std;

int n, num;
int dp[1000];
vector<int> v;
int answer = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		v.push_back(num);
		
		for (int j = 0;j <= i;j++) {
			if (v[i] > v[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += 1;
		answer = max(answer, dp[i]);
	}
	cout << n - answer;
}
