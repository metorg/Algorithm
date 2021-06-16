#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include<stack>

using namespace std;

bool cmp(string a, string b) {
	
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}

	int sum = 0;
	int sum2 = 0;
	for (int i = 0; i < a.length(); i++) {
		if ('0' <= a[i] && a[i] <= '9') {
			sum += a[i] - '0';
		}
		if ('0' <= b[i] && b[i] <= '9') {
			sum2 += b[i] - '0';
		}
	}
	if (sum != sum2) return sum < sum2;
	
	return a < b;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	string s;

	vector<string> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}