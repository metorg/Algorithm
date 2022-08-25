#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int n, num,index;
int tmp = 0;

int dp[1001];
int trace[1001];

vector<int> v;
vector<int> answer;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		for (int j = 0; j <i; j++) {
			if (v[i] > v[j]) {
				if (dp[i] < dp[j]) {
					dp[i] = dp[j];
					trace[i] = j;
				}				 
			}
		}
		dp[i]++;
		if (tmp < dp[i]) {
			tmp = dp[i];
			index = i;
		}
	}
	
	int answer_count = dp[index];

	for (int i = 0; i < answer_count; i++) {
		answer.push_back(v[index]);
		index = trace[index];
	}

	cout << answer.size() << '\n';
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << ' ';
	}
}
