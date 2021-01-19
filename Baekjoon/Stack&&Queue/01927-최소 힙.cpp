#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n,num;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		if (num == 0) {
			if (pq.empty())cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(num);
	}

}