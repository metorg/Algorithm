#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<string.h>

using namespace std;

vector<long long> table;
int n, m;
long long num;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	
	long long temp = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		temp = max(temp, num);
		table.push_back(num);
	}

	long long left = 1;
	long long right = temp*m;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < table.size(); i++) {
			sum += (mid / table[i]);
		}
		if (sum >= m) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	cout << left;
}