#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector<int> v = { 1000000 };

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
	cout << v.size();
	
	
}
