#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int remocon[10] = {};
int cnt = 1e9;
int r = 0;
int channel_num = 0;

string channel;

void dfs(int sum, int depth) {

	if (depth <= channel.size() + 1) {
		if (depth != 0) {
			if ((abs(channel_num - sum) + depth) <= (cnt + r)) {
				cnt = abs(channel_num - sum);
				r = depth;
			}
		}
	}
	else return;

	for (int i = 0;i <= 9;i++) {
		if (remocon[i])continue;
		dfs((sum * 10) + i, depth + 1);
	}

	return;
}
int main() {
	int num, n;

	cin >> channel;
	cin >> n;

	for (int j = 0;j < n;j++) {
		cin >> num;
		remocon[num] = 1;
	}

	for (int i = 0;i < channel.size();i++) channel_num = (channel_num * 10) + channel[i] - '0';

	cnt = abs(100 - channel_num);

	dfs(0, 0);

	cout << cnt + r;
}