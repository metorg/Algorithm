#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include<cmath>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	vector<int> v;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int left = 0;
	int right = v.size() - 1;
	int answer = 0, answer2 = 0;
	int tmp = 2e9;
	
	while (left < right) {
		
		int mid = v[right] + v[left];
		
		if (tmp > abs(mid)) {
			tmp = abs(mid);
			answer = v[left];
			answer2 = v[right];
			
			if (mid == 0)break;
		}

		if (mid < 0)left++;
		else right--;
			
	}

	cout << answer << ' ' << answer2;

}

