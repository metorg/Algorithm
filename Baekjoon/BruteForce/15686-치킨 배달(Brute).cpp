#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>


using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> v;
int n, m;

int ans = 2e9;
void brute(int size) {

	if (v.size() == m) {
		int msum = 0;
		for (int i = 0;i < home.size();i++) {
			int sum = 2e9;
			for (auto j : v) {

				sum = min(sum, abs((home[i].first) - (chicken[j].first)) + abs((home[i].second) - (chicken[j].second)));
			}
			msum += sum;
		}
		ans = min(ans, msum);
		return;
	}

	for (int i = size;i < chicken.size();i++) {
		v.push_back(i);
		brute(i + 1);
		v.pop_back();
	}
}
int main() {

	cin >> n >> m;

	int num2;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> num2;
			if (num2 == 1) {
				home.push_back({ i, j });
			}
			else if (num2 == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	brute(0);
	cout << ans;
}
