#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,num;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (!pq.empty()) {
				cout <<pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';

		}
		else pq.push(num);
	}
}