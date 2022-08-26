#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,num;
vector<int> v = { 100000001 };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > v.back())v.push_back(num);
		else {
			v[lower_bound(v.begin(), v.end(), num)-v.begin()]=num;
		}
	}
	cout << v.size()<<'\n';	
}
