#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>
#include<string>

using namespace std;

int n, m, num;
vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> num;
		v.push_back(num);
	}

	int start = 0;
	int end = 1;
	int result = 1e9;
	int value = v[0] + v[1] - m;
	int flag = 0;

	while (1) {

		if (end == v.size() - 1) flag = 1;
		
		if (value >= 0) result = min(result, (end - start) + 1);

		if (end == v.size() - 1 && start == v.size() - 1)break;

		if (!flag) {
			if (value < 0) {
				end += 1;
				value += v[end];
			}

			else {
				start += 1;
				value -= v[start - 1];
			}

			if (start == end) {//수 하나로도 부분합을 만들수 있을때를 고려
				if (value >= 0) result = min(result, (end - start) + 1);
				end += 1;
				value += v[end];
			}
		}
		else {
			start += 1;
			value -= v[start - 1];
		}

	}

	if (result == 1e9) cout << 0;
	else cout << result;
}