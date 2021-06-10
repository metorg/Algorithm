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

using namespace std;

int n, m;
int num_list[100000];
int start = 1;
int last = 0;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> num_list[i];
		if (last < num_list[i]) {
			last = num_list[i];
		}
	}
	while (start <= last) {
		int mid = (start + last) / 2;
		cout << mid;
		int sum = 0;
		for (int i = 0;i < n;i++) {
			if (num_list[i] > mid) sum += num_list[i] - mid;
		}
		if (sum >= m) start = mid + 1;
		else last = mid - 1;
	}
	cout << last;
}