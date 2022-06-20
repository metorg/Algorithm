#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

queue<int> truck;
queue<pair<int, int>> q;
int main(){

	ios::sync_with_stdio(false);

	int n, w, l;
	int num;
	int answer = 0;

	cin >> n >> w >> l;

	for (int i = 0; i < n; i++) {
		cin >> num;
		truck.push(num);
	}

	int weight = 0;

	for (int i = 1;; i++) {
		if (!q.empty()) {
			if (i - q.front().second == w) {
				weight -= q.front().first;
				q.pop();
			}
		}
		if (weight+truck.front() <= l) {
			q.push({ truck.front(),i });
			weight += truck.front();
			truck.pop();
		}
		if (truck.empty()) {
			answer = i;
			break;
		}

	}	
	cout << answer+w;
}
