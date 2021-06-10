#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	int size;
	int num, num2;
	cin >> size;
	for (int i = 0;i < size;i++) {
		cin >> num >> num2;
		v.push_back(pair<int, int>(num, num2));
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < size;i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}