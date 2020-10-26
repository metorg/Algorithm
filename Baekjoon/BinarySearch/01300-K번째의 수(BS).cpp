#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int left = 1;
	int right = k;
	int mid = 1;
	int result = -1;
	while (left <= right) {
		int cnt = 0;
		mid = ((left + right) / 2);
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) {
			left = mid + 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}
	cout << result;
}