#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,num;
vector<int> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total_sum = 0;
	long long answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		total_sum += num;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		answer += v[i] * (total_sum - v[i]);
		total_sum -= v[i];
	}

	cout << answer;
}
