#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N, P, M,L,X;
string s;
priority_queue<pair<int, int>> max_pq, min_pq;
int visit[100001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		max_pq.push({L,P });
		min_pq.push({ -L,-P });
		visit[P] =L;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s == "add") {
			cin >> P >> L;
			max_pq.push({ L,P });
			min_pq.push({ -L,-P });
			visit[P]=L;
		}
		else if (s == "recommend") {
			cin >> X;
			if (X == 1) {
				while (!max_pq.empty()) {
					if (max_pq.top().first==visit[max_pq.top().second]) {
						cout << max_pq.top().second << '\n';
						break;
					}
					else {
						max_pq.pop();
					}
				}
			}
			else {
				while (!min_pq.empty()) {
					if (-min_pq.top().first==visit[-min_pq.top().second]) {
						cout << -min_pq.top().second << '\n';
						break;
					}
					else {
						min_pq.pop();
					}
				}

			}
		}
		else {
			cin >> P;
			visit[P] =0;
		}		
	}

}

