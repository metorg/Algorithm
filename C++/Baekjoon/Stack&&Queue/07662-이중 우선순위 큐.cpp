#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, num, c_num;
char ch;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++) {
		priority_queue<int, vector<int>, less<int>> top_pq;
		priority_queue<int, vector<int>, greater<int>> less_pq;
		unordered_map<int, int> m;
		cin >> num;

		for (int j = 0;j < num;j++) {
			cin >> ch >> c_num;
			if (ch == 'I') {
				top_pq.push(c_num);
				less_pq.push(c_num);
				m[c_num]++;
			}
			else {

				if (c_num == 1) {
					while (!top_pq.empty()) {
						if (m[top_pq.top()] == 0)top_pq.pop();
						else break;
					}
					if (!top_pq.empty()) {
						m[top_pq.top()]--;
						top_pq.pop();
					}


				}
				else if (c_num == -1) {
					while (!less_pq.empty()) {
						if (m[less_pq.top()] == 0)less_pq.pop();
						else break;
					}
					if (!less_pq.empty()) {
						m[less_pq.top()]--;
						less_pq.pop();
					}
				}
			}

		}
		while (!top_pq.empty()) {
			if (m[top_pq.top()] == 0)top_pq.pop();
			else break;
		}
		while (!less_pq.empty()) {
			if (m[less_pq.top()] == 0)less_pq.pop();
			else break;
		}
		if (top_pq.empty() || less_pq.empty())cout << "EMPTY" << '\n';
		else cout << top_pq.top() << ' ' << less_pq.top() << '\n';

	}

}