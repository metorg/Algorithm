#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include<set>

using namespace std;

int k,num;
vector<int>answer[11];
vector<int>v;

void search(int start, int end,int depth) {
	if (start == end) {
		answer[depth].push_back(v[start]);
		return;
	}
	int mid = (start + end) / 2;
	answer[depth].push_back(v[mid]);

	search(start, mid - 1,depth+1);
	search(mid + 1, end,depth+1);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < pow(2, k) - 1; i++) {
		cin >> num;
		v.push_back(num);
	}
	search(0, v.size() - 1,0);
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

}

