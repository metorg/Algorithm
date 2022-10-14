#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	int answer = 0;
	cin >> n >> k;
	
	if (n <= k)cout << 0;
	else {
		while (1) {
			int cnt = 0;
			int tmp = n;
			while (tmp>0) {
				if (tmp % 2 == 0) {
					tmp /= 2;
				}
				else {
					tmp /= 2;
					cnt++;
				}
			}
			if (cnt <= k)break;

			n++;
			answer++;
		}
		cout << answer;
	}

}
