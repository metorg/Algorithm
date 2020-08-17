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
int sum = 0;
int msum = 0;
int ans = 202;
void brute(int size, int cnt) {

	if (cnt == m) {
		msum = 0;
		for (int i = 0;i < home.size();i++) {
			sum = 202;
			for (auto j : v) {
				sum = min(sum, abs((home[i].first + 1) - (chicken[j].first + 1)) + abs((home[i].second + 1) - (chicken[j].second + 1)));

			}

			msum += sum;
		}

		ans = min(ans, msum);
		return;
	}
	cout << chicken.size() << endl;
	for (int i = size;i < chicken.size();i++) {
		v.push_back(i);
		brute(i + 1, cnt + 1);
		v.pop_back();
	}
}
int main() {
	cin >> n >> m;

	int num2;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> num2;
			if (num2 == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (num2 == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	brute(0, 0);
	cout << ans;
}
