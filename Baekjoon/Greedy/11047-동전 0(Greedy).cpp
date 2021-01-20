#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;


int main() {
	
	int n, num, target;
	int cnt = 0;
	
	vector<int> coin;

	cin >> n >> target;
	for (int i = 0;i < n;i++) {
		cin >> num;
		coin.push_back(num);
	}

	sort(coin.begin(), coin.end());

	while (target) {
		int i = 0;

		for (i = 0;i<coin.size();i++)
			if (coin[i] > target)break;
		
		if (i == 0) {
			cnt += target / coin[0];
			target =target% coin[0];

		}
		else {
			cnt += target / coin[i - 1];
			target = target % coin[i - 1];
		}
	}
	cout << cnt;

}
