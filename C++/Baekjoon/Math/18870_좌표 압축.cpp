#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

map<int, int> m;
vector<int> v;
int n, num;
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (!m[num])m[num] = 1;
		v.push_back(num);
	}
	int cnt = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		iter->second = cnt;
		cnt++;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << m[v[i]] << ' ';
	}
}
